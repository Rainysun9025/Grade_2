#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;   // 顶点数上限，根据题目调整

// ===================== 并查集部分 =====================
// 并查集用于快速判断两个顶点是否已经在同一个连通块中
// 以及合并两个连通块

int fa[N];   // fa[x] 表示 x 的父节点，路径压缩后指向代表元
int rk[N];   // rk[x] 表示以 x 为根的集合的秩（近似高度），用于按秩合并

// 查找 x 所在集合的代表元（根节点）
// 路径压缩：把查找路径上的所有节点直接挂到根上，加速后续查询
int find(int x) {
    if (fa[x] != x)          // 如果 x 不是根
        fa[x] = find(fa[x]); // 递归找到根，并把 x 直接连到根上
    return fa[x];            // 返回根
}

// 合并 x 和 y 所在的两个集合
// 返回值：true 表示合并成功（原本不在同一集合）
//           false 表示 x 和 y 已经在同一集合，无需合并
bool unite(int x, int y) {
    int fx = find(x);        // 找 x 的根
    int fy = find(y);        // 找 y 的根

    if (fx == fy) return false;  // 已经在同一集合，合并失败

    // 按秩合并：让秩小的树挂到秩大的树下，保持树较矮
    if (rk[fx] < rk[fy]) swap(fx, fy);

    fa[fy] = fx;             // 把 fy 挂到 fx 下

    // 如果两棵树秩相同，合并后秩加一
    if (rk[fx] == rk[fy]) rk[fx]++;

    return true;             // 合并成功
}

// ===================== 边结构体 =====================

struct Edge {
    int u, v;                // 边的两个端点
    long long w;             // 边权，可能很大，用 long long

    // 重载小于号，用于 sort 按边权升序排序
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// ===================== 主函数 =====================

int main() {
    ios::sync_with_stdio(false);   // 关闭 cin/cout 与 C 标准 IO 的同步，加速输入
    cin.tie(nullptr);              // 解除 cin 与 cout 的绑定，进一步加速

    int n, m;
    cin >> n >> m;   // n: 顶点数，m: 边数，顶点编号 1~n

    // 读入所有边
    vector<Edge> edges;
    edges.reserve(m);   // 预分配空间，避免反复扩容

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;              // 读入一条边：u --w-- v
        edges.push_back({u, v, w});      // 加入边集
    }

    // ============ 第一步：按边权从小到大排序 ============
    // Kruskal 的核心贪心策略：优先选权值最小的边
    sort(edges.begin(), edges.end());

    // ============ 第二步：初始化并查集 ============
    // 每个顶点一开始自成一个集合
    for (int i = 1; i <= n; i++) {
        fa[i] = i;    // 自己是自己的父节点，即自己是根
        rk[i] = 0;    // 初始秩为 0
    }

    // ============ 第三步：贪心加边 ============
    long long ans = 0;   // 最小生成树的边权和
    int cnt = 0;         // 已加入生成树的边数

    for (auto& e : edges) {              // 按边权从小到大遍历每条边
        if (unite(e.u, e.v)) {           // 如果两端不在同一连通块，加入这条边
            ans += e.w;                  // 累加边权
            cnt++;                       // 已选边数加一

            if (cnt == n - 1) break;     // 生成树恰好 n-1 条边，提前结束
        }
        // 如果两端已经在同一连通块，说明加入这条边会形成环，跳过
    }

    // ============ 第四步：判断结果 ============
    if (cnt == n - 1) {
        // 成功选出 n-1 条边，图连通，存在最小生成树
        cout << ans << '\n';
    } else {
        // 边数不足 n-1，说明图不连通，不存在最小生成树
        // 按题目要求可能输出 -1、"impossible"、"No MST" 等
        cout << -1 << '\n';
    }

    return 0;
}