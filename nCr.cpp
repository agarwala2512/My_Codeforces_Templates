const int MAX = 1e6 + 10;
const ll MOD = 1e9 + 7;
ll fact[MAX];
ll invfact[MAX];

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
        b >>= 1;
    }
    return res % mod;
}
void calculate() {
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for (int i = 2; i < MAX; i ++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = ((invfact[i - 1]) * binpow( i, MOD - 2)) % MOD;
    }
}
ll modInverse(ll n) {
    return binpow(n, MOD - 2) % mod;
}
ll nCr(ll n, ll r) {
    if (n < r) return 0;
    return ((fact[n] * invfact[n - r]) % MOD * (invfact[r]) % MOD) % MOD;
}