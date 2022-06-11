ll spf[N];

// vector<char> is_prime(N + 1, true);

void precalculate() {
    // is_prime[0] = is_prime[1] = false;
    spf[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = i * i; j < N; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}