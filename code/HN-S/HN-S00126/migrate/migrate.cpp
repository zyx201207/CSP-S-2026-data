#include <cstdio>
#include <deque>
#include <ios>
#include <iostream>

static constexpr int MAX_SIZE = 2e6;

static int test_id, tests_cnt;
static int len;
static long long limit;
static long long data[MAX_SIZE + 5];

namespace force {
    static constexpr int MAX_SIZE_FORCE = 5000;
    
    static int answer;
    static int min_times[MAX_SIZE_FORCE + 5];
    static int value_cnt[MAX_SIZE_FORCE + 5];
    static int paths_cnt[MAX_SIZE_FORCE + 5];
    
    static void solve();
    static void calc(int start);
}

int main() {
    std::freopen("migrate.in", "r", stdin);
    std::freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // auto memory = sizeof(test_id) + sizeof(tests_cnt) + sizeof(len) + sizeof(limit) + sizeof(data) + sizeof(force::answer) + sizeof(force::min_times) + sizeof(force::value_cnt) + sizeof(force::paths_cnt);
    // std::cerr << "Static Memory: " << (memory / 1024.0 / 1024.0) << " MB" << '\n';

    std::cin >> test_id >> tests_cnt;
    for (int i = 1; i <= tests_cnt; i++) {
        // if (test_id <= 10) {
            force::solve();
        // }
    }

    return 0;
}

namespace force {
    static void solve() {
        std::cin >> len >> limit;
        for (int i = 1; i <= len; i++) {
            std::cin >> data[i];
        }

        answer = 0;
        for (int start = 1; start <= len; start++) {
            calc(start);
        }

        std::cout << answer << '\n';
    }

    static void calc(int start) {
        for (int i = 0; i <= len; i++) {
            value_cnt[i] = 0;
            paths_cnt[i] = 0;
        }
        
        min_times[start] = 0;
        std::deque<int> window;
        window.push_back(start);
        int left = start;
        value_cnt[0] = 1;
        paths_cnt[start] = 1;
        // int last_i = len;
        for (int i = start + 1; i <= len; i++) {
            while (left <= i && data[i] - data[left] > limit) {
                left++;
            }
            while (!window.empty() && window.front() < left) {
                value_cnt[min_times[window.front()]]--;
                window.pop_front();
            }
            if (window.empty()) {
                // last_i = i;
                break;
            };
            int minimum = min_times[window.front()];
            int vcnt = value_cnt[minimum];
            min_times[i] = minimum + 1;
            value_cnt[min_times[i]]++;
            int cnt = 0;
            for (int ptr = window.front(); ptr <= window.front() + vcnt - 1; ptr++) {
                cnt += paths_cnt[ptr];
            }
            if (cnt == 2) {
                answer++;
            }
            paths_cnt[i] = cnt;
            window.push_back(i);
        }
        // std::cerr << "start = " << start << '\n';
        // std::cerr << "  ";
        // for (int i = start; i <= last_i; i++) {
        //     std::cerr << min_times[i] << ' ';
        // }
        // std::cerr << '\n';
    }
}
