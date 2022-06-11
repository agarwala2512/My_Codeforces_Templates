void add(long long &a, long long b) {
    b %= mod;
    a = (a + b) % mod;
}
void mul(long long &a, long long b) {
    b %= mod;
    a = (a * b) % mod;
}
void sub(long long &a, long long b) {
    b %= mod;
    a = (a - b) % mod;
    a = (a + mod) % mod;
}