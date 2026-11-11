#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N],n,m,ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        stack<int> s;
        int Isvis[N];
        memset(Isvis,0,sizeof Isvis);
        for (int j=i;j<=n;j++)
        {
            if (Isvis[a[j]]==0)
            {
                Isvis[a[j]]++;
                s.push(a[j]);
            }
            else
            {
                while(s.top()!=a[j])
                {
                    s.pop();
                    Isvis[a[j]]--;
                }
                s.pop();
                s.push(a[j]);
            }
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
