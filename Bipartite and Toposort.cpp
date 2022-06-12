vll g[N];
int col[N], topo[N];
void dfs(int u, int c) {
    col[u] = c;
    for (int v : g[u]) {
        if (col[v] == -1)dfs(v, 1 - c);
    }
}
bool isBipartite(int n) {

    for (int i = 1; i <= n; i++)col[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            dfs(i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int x : g[i]) {
            if (col[i] == col[x])return false;
        }
    }
    return true;
}

bool Toposort(int n) {
    // Will return false if contains cycle
    vector<int>in(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int x : g[i]) {
            in[x]++;
        }
    }
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    int ord = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo[u] = ++ord;
        for (int v : g[u]) {
            in[v]--;
            if (!in[v])q.push(v);
        }
    }
    return ord == n;
}