vector<int> kmp(string& s)
{
    int n = s.size();
    vll a(n);
    if (n == 1)return a;
    for (int i = 0, j = 1; j < n;) {
        if (s[i] == s[j]) {
            a[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                j++;
            } else
            {
                i = a[i - 1];
            }
        }
    }
    return a;
}