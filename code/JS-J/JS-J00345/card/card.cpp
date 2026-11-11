#include <bits/stdc++.h>
using namespace std;
int n,m;
int* a;
stack<int> st;
int* cnt;
bool* has;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    a = new int[n];
    cnt = new int[m + 1]();
    has = new bool[m + 1]();
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        memset(has,0,sizeof(bool) * (m + 1));
        for(int j = i;j < n;j++)
        {
            while(!st.empty() && has[a[j]])
            {
                int tmp = st.top();
                has[tmp] = 0;
                st.pop();
            }
            st.push(a[j]);
            has[a[j]] = 1;
        }
        for(int i = 1;i <= m;i++)
        {
            if(has[i]) cnt[i]++;
        }
    }
    for(int i = 1;i <= m;i++) cout << cnt[i] << ' ';
    return 0;
}
