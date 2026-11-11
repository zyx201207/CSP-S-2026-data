#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int s[N],tmp[N],cnt[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;++i)
    {
        int tot=1;
        for(int j=i;j<=n;++j)
        {
            if(tot==1) tmp[tot++]=s[j];
            else
            {
                bool flag=false;
                for(int k=1;k<tot;++k)
                {
                    if(s[j]==tmp[k])
                    {
                        tot=k+1;
                        flag=true;
                        break;
                    }
                }
                if(!flag) tmp[tot++]=s[j];
            }
        }
        for(int k=1;k<tot;++k) cnt[tmp[k]]+=1;
    }
    for(int i=1;i<=m;++i) cout<<cnt[i]<<' ';
    return 0;
}
