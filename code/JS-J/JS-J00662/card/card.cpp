#include <bits/stdc++.h>
using namespace std;

int s[500009],cnt[300009];
int endp[300009];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        endp[s[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            //cout<<s[j]<<" "<<endp[s[j]]<<"  ";
            if(endp[s[j]]==j)
            {
                cnt[s[j]]++;
                continue;
            }
            j=endp[s[j]]-1;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
