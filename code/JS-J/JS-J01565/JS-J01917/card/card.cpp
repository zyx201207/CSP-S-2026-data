#include<bits/stdc++.h>
using namespace std;

int a[500010];
bool mark[300010];
int sum[300010];


int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    bool flag = m<=2;
    bool flag2 = true;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
        if(i!=1 && a[i]<a[i-1])
        {
            flag2 = false;
        }
    }
    if(flag)
    {
        if(m==1)
        {
            cout << n;
        }
        else
        {
            int ans1 = 0,ans2 = 0;
            for(int i = 1; i<=n; i++)
            {
                if(a[i]==1)
                {
                    ans1++;
                }
                else
                {
                    ans2++;
                }
            }
            if(a[n]==1)
            {
                cout << n << " " << ans2;
            }
            else
            {
                cout << ans1 << " " << n;
            }
        }

    }
    else if(flag2)
    {
        a[n+1] = -1;
        int p = 0;
        for(int i = n; i>=1; i--)
        {
            if(a[i]!=a[i+1])
            {
                sum[a[i]] = n-p;
            }
            p++;
        }
        for(int i = 1; i<=m; i++)
        {
            cout << sum[i] << " ";
        }
    }
    else
    {
        for(int i = 1; i<=n; i++)
        {
            stack<int> stk;
            memset(mark,0,sizeof(mark));
            for(int j = i; j<=n; j++)
            {
                if(!mark[a[j]])
                {
                    stk.push(a[j]);
                    mark[a[j]] = true;
                }
                else
                {
                    while(stk.top()!=a[j])
                    {
                        mark[stk.top()] = false;
                        stk.pop();
                    }
                }
            }
            while(!stk.empty())
            {
                sum[stk.top()]++;
                stk.pop();
            }
        }
        for(int i = 1; i<=m; i++)
        {
            cout << sum[i] << " ";
        }
    }
    return 0;
}
