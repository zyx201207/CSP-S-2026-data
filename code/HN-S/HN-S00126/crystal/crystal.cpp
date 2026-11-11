#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>

static constexpr int MAX_SIZE = 5e5;

static int len;
static long long limit;
static long long data[MAX_SIZE + 5];
static long long presum[MAX_SIZE + 5];

static void solve();

int main() {
    std::freopen("crystal.in", "r", stdin);
    std::freopen("crystal.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

static void solve() {
    std::cin >> len >> limit;
    for (int i = 1; i <= len; i++) {
        std::cin >> data[i];
    }

    std::sort(data + 1, data + len + 1);
    for (int i = 1; i <= len; i++) {
        presum[i] = presum[i - 1] + data[i];
    }

    int answer = 1;
    int left = 1;
    for (int right = 1; right <= len; right++) {
        long long sum = presum[right] - presum[left - 1];
        long long need = data[right] * (right - left + 1);
        long long delta = need - sum;
        if (delta <= limit) {
            answer = std::max(answer, right - left + 1);
        } else {
            while (left <= right) {
                left++;
                long long now_sum = presum[right] - presum[left - 1];
                long long now_need = data[right] * (right - left + 1);
                long long now_delta = now_need - now_sum;
                if (now_delta <= limit) {
                    answer = std::max(answer, right - left + 1);
                    break;
                }
            }
        }
    }

    std::cout << answer << '\n';
}
