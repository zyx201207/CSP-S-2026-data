#include <bits/stdc++.h>
using namespace std;

long long a[200020],n,f[200020],ans[200020],m;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        memset(f,0,sizeof f);
        list<int>l;
        for(int j=i;j<=n;j++)
        {
            if(f[a[j]]==0)
            {
                l.push_back(a[j]);
                f[a[j]]=1;
            }
            else{
                while(l.back()!=a[j])
                {
                    f[l.back()]=0;
                    l.pop_back();
                }
            }
        }
        while(!l.empty())
        {
            ans[l.front()]++;
            l.pop_front();
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
    return 0;
}
