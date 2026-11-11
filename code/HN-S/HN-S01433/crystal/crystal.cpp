#include <algorithm>
#include <cstdio>

const int IH = 39;
const int maxn = 5e5 + IH;

long long m, n, ans = 0;
long long a[maxn], diff[maxn], preDiff[maxn];

int main(void)
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

// Read the data.
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

// Sort the numbers.
    std::sort(a + 1, a + n + 1);

// pre-calculate the numbers.
    a[0] = a[1];
    for (int i = 1; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
        preDiff[i] = preDiff[i - 1] + diff[i];
    }

// dual-pointer solver.
    long long leftPointer = 1, rightPointer = 1, sum = 0, preSum = 0;
    for ( ; leftPointer <= n && rightPointer <= n; ) {
        while (sum <= m && rightPointer <= n) {
            rightPointer++;
            preSum += preDiff[rightPointer - 1];
            sum = (rightPointer - leftPointer) * preDiff[rightPointer] - preSum;
        }ans = std::max(ans, rightPointer - leftPointer);
        while (sum > m && leftPointer <= n) {
            leftPointer++;
            preSum -= preDiff[leftPointer - 1];
            sum = (rightPointer - leftPointer) * preDiff[rightPointer] - preSum;
        }
    }

// Final output.
    printf("%lld\n", ans);

}
