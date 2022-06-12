vpll adj[N];
ll dist[N], par[N];
priority_queue<pll, vpll, greater<pll>>p;
void dijstra(int src)
{
    for (int i = 0; i < N; i++)dist[i] = INF;
    dist[src] = 0;
    par[1] = 0;
    p.push({0, src});
    while (!p.empty())
    {
        ll k = p.top().ss;
        p.pop();
        for (auto x : adj[k])
        {
            if (dist[x.ff] > dist[k] + x.ss)
            {
                par[x.ff] = k;
                dist[x.ff] = dist[k] + x.ss;
                p.push({dist[k] + x.ss, x.ff});
            }
        }
    }
}