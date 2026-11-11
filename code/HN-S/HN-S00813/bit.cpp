inline int lowbit (int x) { return x & -x; }
struct bit {
    int t [N + 5];
    void update (int x, int k) {
        for ( ; x <= N ; x += lowbit (x))
            t [x] += k;
    }
    int query (int x) { int ans;
        for (ans = 0 ; x ; x -= lowbit (x))
            ans += t [x];
        return ans;
    }
};