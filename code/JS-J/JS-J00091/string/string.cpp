#include<bits/stdc++.h>
#define int long long
using namespace std;
/* define & const */
const int N = 2e5 + 10;
/* struct */
struct s
{
    char c;
    int num;
};
/* Variables */
s str1[N];
s str2[N];
long long p; // left
long long q;// right
long long len = 0;
int n, n_2;
long long goal = 0;
long long res = 0;
/* Function */
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) // 1-based
    {
        cin >> str1[i].num;
        len += str1[i].num;
        cin >> str1[i].c;
    }
    if (len % 2 == 1) // odd
    {
        // cout << "odd!\n";
        int where = 0;
        int id = 0;
        int mid = len / 2 + 1; // the middle
        int flag = 1;
        goal = mid - 1;
        for (int i = 1; i <= n; i++)
        {
            where += str1[i].num;
            if (where >= mid && flag == 1)
            {
                flag = 0;
                int l_len = mid - where + str1[i].num - 1;
                int r_len = str1[i].num - l_len - 1;//remove the middle one, since it doesn't affect the answer at all;
                if (l_len != 0)
                {
                    // cout << "l!\n"; 
                    str2[++id].num = l_len;
                    str2[id].c = str1[i].c;
                }
                if (r_len != 0)
                {
                    // cout << "r!\n";
                    str2[++id].num = r_len;
                    str2[id].c = str1[i].c;
                }
            }
            else
            {
                str2[++id].num = str1[i].num;
                str2[id].c = str1[i].c;
            }
        }
        n_2 = id;
        len--;
    }
    else // even
    {
        int where = 0;
        int id = 0;
        int mid = len / 2 + 1; // the middle (right one)
        int flag = 1;
        goal = mid - 1;
        for (int i = 1; i <= n; i++)
        {
            where += str1[i].num;
            if (where >= mid && flag == 1)
            {
                flag = 0;
                int l_len = mid - where + str1[i].num - 1;
                int r_len = str1[i].num - l_len; // the length is even, so we can't remove the middle one as it affect the result.
                if (l_len != 0)
                {
                    str2[++id].num = l_len;
                    str2[id].c = str1[i].c;
                }
                if (r_len != 0)
                {
                    str2[++id].num = r_len;
                    str2[id].c = str1[i].c;
                }
            }
            else
            {
                str2[++id].num = str1[i].num;
                str2[id].c = str1[i].c;
            }
        }
        n_2 = id;
    }
    //for (int i = 1; i <= n_2; i++)
    //{
        //cout << str2[i].num << " * " << str2[i].c << "\n";
    //}
}
void solve()
{
    p = 0;
    int p_id = 0;
    q = len + 1;
    int q_id = n_2 + 1;
    while(p != goal)
    {
        int q_move_dis = 0, p_move_dis = str2[++p_id].num;
        p += p_move_dis;
        while(q_move_dis + str2[q_id - 1].num <= p_move_dis)
        {
            q_move_dis += str2[--q_id].num;
            if(str2[q_id].c != str2[p_id].c)
            {
                res += str2[q_id].num;
            }
        }
        if (str2[q_id - 1].c != str2[p_id].c)
        {
            res += p_move_dis - q_move_dis;
            str2[q_id - 1].num -= p_move_dis - q_move_dis;
            q -= p_move_dis;
        }
        else
        {
            str2[q_id - 1].num -= p_move_dis - q_move_dis;
            q -= p_move_dis;
        }
        //assert(len + 1 - q == p);
    }
}
/* main */

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    cout << res << "\n";
    return 0;
}