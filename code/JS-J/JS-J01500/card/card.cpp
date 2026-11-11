#include <bits/stdc++.h>
using namespace std;
#define int long long
int n=0,m=0;
int a[5005]={0},b[3005]={0},ans[3005]={0};
stack<int> s;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        b[3005]={0};
        for(int j=i;j<=n;j++)
        {
            b[a[j]]++;
            if(b[a[j]]==2)
            {
                while(!s.empty())
                {
                    if(s.top()==a[j])
                    {
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                b[a[j]]=1;
            }
            s.push(a[j]);
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
