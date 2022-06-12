int spf[N];
void calc() {
    // spf[i]=0 means it's a prime number;
    // 1 is a special case which needs to be handled carefully
    // spf upto 2e7(<- for this template) (or maybe higher)
    for (int i = 2; i <= 2e3; i++) {
        if (spf[i] != 0)continue;
        for (int j = i * i; j <= 2e7; j += i) {
            if (!spf[j])
                spf[j] = i;
        }
    }
    /*
        // now I want all the factors of x in log x
        set<int>factors;
        factors.insert(1);
        factors.insert(x);
        while (spf[x] != 0) {
            int val = spf[x];
            factors.insert(val);
            while (x % val == 0)x /= val, factors.insert(x);
        }
        for (int i : factors)cout << i << " ";
    */
    /*
        // now I want all the prime factors of x in log x
        vector<int>factors;
        while (spf[x] != 0) {
            int val = spf[x];
            factors.push_back(val);
            while (x % val == 0)x /= val;
        }
        if (x != 1)factors.push_back(x);
        for (int i : factors)cout << i << " ";

    }
    */
}