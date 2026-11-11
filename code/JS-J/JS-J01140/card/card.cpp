#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+10;
int a[N],cnt[M],zccnt[M],n,m,ct;
bool c[M],A = 1;
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
    {
        cin >> a[i];
        if(a[i]<a[i-1])A = 0;
    }
    if(A)
    {
        for(int i = 1; i<= n; i++)
        {
            cin >> a[i];
            zccnt[a[i]]++;
        }
        cnt[1] = zccnt[1];
        for(int i=2;i<= m; i++)
        {
            cnt[i] =cnt[i-1]+zccnt[i];
        }
        for(int i=1;i<= m; i++)cout << cnt[i] << " ";
    }
    else
    {
        for(int i = 1;i<= n;i++)
        {
        ct++;
        memset(c,0,sizeof(c));
        for(int j = ct;j<= n;j++)
        {
            if(!c[a[j]])
            {
                s.push(a[j]);
                c[a[j]] = 1;
            }
            else
            {
                while(1)
                {
                    if(s.top()!= a[j])
                    {
                        c[s.top()] = 0;
                        s.pop();
                    }
                    else
                    {
                        c[s.top()] = 0;
                        s.pop();
                        break;
                    }
                }
                s.push(a[j]);
                c[a[j]] = 1;
            }
        }
        while(!s.empty())
        {
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i<= m;i++)cout << cnt[i] << " ";
    }
    return 0;
}
