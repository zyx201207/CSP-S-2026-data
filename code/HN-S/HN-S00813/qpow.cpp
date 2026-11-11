int qpow (int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) (res *= x) %= mod;
        (x *= x) %= mod; (n >>= 1);
    } return res;
}