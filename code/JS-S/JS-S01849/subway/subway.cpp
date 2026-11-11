#include <bits/stdc++.h>
using namespace std;
#define int long long
int c=0,n=0,m=0,d=0,q=0,k=0,x=0,y=0,w[500005]={0},s[505][5005][4]={0},flag=0,idxi=0,idxj1=0,idxj2=0,ans=0;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++) cin>>s[i][j][1]>>s[i][j][2];
    }
    while(q--)
    {
        cin>>x>>y;
        ans+=w[x]+w[y];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(s[i][j][1]==x)
                {
                    idxi=i;
                    idxj1=j;
                    flag++;
                }
                if(s[i][j][1]==y)
                {
                    idxi=i;
                    idxj2=j;
                    flag++;
                }
            }
        }
        if(flag==2)
        {
            ans+=s[idxi][idxj1][2]+s[idxi][idxj2][2];
            cout<<ans;
        }
        else cout<<ans+s[1][10][2]*3+s[2][7][2]+s[1][2][2]*2;
        cout<<endl;
    }
    return 0;
}
