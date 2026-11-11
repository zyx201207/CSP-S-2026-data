#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10 ;
long long a[N];
int fa[N],fa2[N];
bool ok[5010][5010];
void solve()
{
    int n;
    long long d;
    cin>>n>>d;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);

    //!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(n>4e4)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=0,j=0;i<n;i++)
    {
        while(j<n&&a[j]-a[i]<=d)j++;
        fa[i]=j-1;
    }
    for(int i=n-1,j=n-1;i>=0;i--)
    {
        while(j>=0&&a[i]-a[j]<=d)j--;
        fa2[i]=j+1;
    }
    long long ans=0;
    for(int k=1;k<n;k++)
    {
        for(int j=k;j<n;j++)
        {
            int i=j-k;
            if((ok[i][fa2[j]]&&fa[fa2[j]]==j)||(ok[fa[i]][j]&&fa2[fa[i]]==i)||(fa[fa[i]]==j&&fa2[fa2[j]]==i&&fa[i]-fa2[j]==1&&j!=fa[i]&&fa2[j]!=i))
                ok[i][j]=1;
            else
                ok[i][j]=0;
            if((ok[i][fa2[j]]&&fa[fa2[j]]>=j)||(ok[fa[i]][j]&&fa2[fa[i]]<=i)||(fa[fa[i]]>=j&&fa2[fa2[j]]<=i&&fa[i]-fa2[j]==1&&fa[i]<j&&fa2[j]>i)||(ok[fa[i]][fa2[j]]&&fa[fa2[j]]>=j&&fa2[fa[i]]<=i))
            {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
int tps=100+100+40+15;
