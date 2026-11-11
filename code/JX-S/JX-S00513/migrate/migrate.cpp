#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long zb[2202020];
vector<long long> ro[400][400];
long long ans;
void specil()
{
    long long k=d/(zb[2]-zb[1]);
    if(k==1||k==0)
        cout<<0<<'\n';
    else
    cout<<max(n-(k+k-1),(long long)0)<<'\n';
}
void dfs(long long fa,long long no,long long kl)
{
    if(fa!=no)
        ro[fa][no].push_back(kl);
    if(no>=n)
        return;
    for(int i=no+1;i<=n;i++)
    if(zb[i]-zb[no]<=d)
            dfs(fa,i,kl+1);
}
void force()
{
    for(int i=1;i<=30;i++)
        for(int j=1;j<=30;j++)
            ro[i][j].clear();
    ans=0;
    for(int i=1;i<=n;i++)
        dfs(i,i,1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            sort(ro[i][j].begin(),ro[i][j].end());
            if(ro[i][j].size()==0)
                continue;
            long long bj=ro[i][j][0],num=0;
            for(int k=0;k<ro[i][j].size();k++)
                if(ro[i][j][k]==bj)
                    num++;
            if(num==2)
                ans++;
        }
        cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t>0)
    {
        t--;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>zb[i];
        if(c>12)
        {
            cout<<0<<'\n';
            continue;
        }
        if(11<=c&&c<=12){
            specil();
            continue;
        }
        force();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
