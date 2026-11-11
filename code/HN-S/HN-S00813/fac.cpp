fac [0] = inv [1] = ifac [0] = 1;
for (int i = 2 ; i <= N ; i ++)
    inv [i] = (mod - mod / i) * inv [mod % i] % mod;
for (int i = 1 ; i <= N ; i ++)
    fac [i] = fac [i - 1] * i % mod,
    ifac [i] = ifac [i - 1] * inv [i] % mod;


// -------------------------------------------

int C (int n, int m) {
    if (n < m) return 0;
    return fac [n] * ifac [m] * ifac [n - m];
}