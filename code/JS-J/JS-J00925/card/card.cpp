#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;

bool A = true;

map<int, int> a, ans;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if (a[i] < a[i - 1]) A = false;
    }
    if (A)
    {
        for (int i = 1; i <= n; i++)
        {
            ans[a[i]] = i;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            //cout << i << endl;
            int cnt = 0;
            map<int, int> t, c;
            for (int j = i; j <= n; j++)
            {
                if (t[a[j]] == 0 || t[a[j]] > cnt)
                {
                    t[a[j]] = ++cnt;
                    c[cnt] = a[j];
                }
                else
                {
                    cnt = t[a[j]];
                }
            }
            for (int j = 1; j <= cnt; j++)
            {
                ans[c[j]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
/*
10:10
I have some
let me think
sort the card need O(2N)
and check need O(2n)
so it's O(4N)
what? O(4N)? I didn't have wrong? it's so fast
5*10^5...
maybe TLE some pts
but it's also so fast
try
10:15
O in all
emm
O(6n)
too fast
10:18
maybe problem let's to use er fen to find the card?
no
it's not sort
10:24
something wrong
10:32
oh I know!
10:41
oh no T^T
11:27
I write the A
can have more 16tps
11:48
I want to shang mihuoxingweidashang
touhou is good
i love sakuya
freeopen
#include <iostream>
#include <bits\stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdalign>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <streambuf>
#include <string>
#include <string_view>
#include <strstream>
#include <map>
#include <vector>
#include <stab.h>
#include <stack>
#include <queue>
#include <err.h>
#include <errno.h>
#include <error.h>
#include <random>
#include <list>
#include <search.h>
#include <ctime>
#include <time.h>
#include <bit>
#include <bits/a.out.h>
#include <bits/algorithmfwd.h>
#include <bits/allocated_ptr.h>
#include <bits/allocator.h>
#include <bits/alloc_traits.h>
#include <bits/argp-ldbl.h>
#include <bits/atomic_base.h>
#include <bits/bits/atomic_futex.h>
#include <bits/atomic_lockfree_defines.h>
#include <bits/atomic_word.h>
#include <bits/bitset>
*/
