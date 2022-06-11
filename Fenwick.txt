#define LSB(i) ((i) & -(i))
const int maxn = N;
struct fenwick {
    int A[maxn];
    int query(int i) {
        int sum = 0;
        while (i > 0)
            sum += A[i], i -= LSB(i);
        return sum;
    }
    void update(int i, int k) {
        if (i < 1)return;
        while (i < maxn)
            A[i] += k, i += LSB(i);
    }
    // after using range update, you can't find the value at specific index using range query _query(l,l)
    // beacuse some part of value also lies in the prefix
    // this is not a normal range update
    void rupd(int l, int r, int v) {
        update(l, v);
        update(r + 1, -v);
    }
    int _query(int l, int r) {
        if (l == 0)return query(r);
        return query(r) - query(l - 1);
    }
} fenw;

void refresh(int n) {
    for (int i = 0; i <= n; i++) {
        fenw.update(i, -fenw.query(i));
    }
}