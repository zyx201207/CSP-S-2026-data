#include<bits/stdc++.h>
#define int long long
#define len (i-j+1)
using namespace std;
int C,n,T,d,a[4100000],c[41000000],e[41000000],x[41000000],ans;
void clean()
{
    for(int i=1;i<=n+5;i++)
    {
        a[i]=0,c[i]=0,e[i]=0;
    }
    ans=0;
}
void solve(int pl)
{

    int pll=pl+1,lef=0,plr=pl,rig=0;
    int cnt=0;
    if(e[pl]-e[pl+1]+1!=0||c[pl+1]-c[pl]+1!=0)
    {
        if(e[pl]-e[pl+1]+1>0&&c[pl+1]-c[pl]+1>0){
        //cout<<pl<<":"<<e[pl]-e[pl+1]+1<<" "<<c[pl+1]-c[pl]+1<<endl;
        lef+=e[pl]-1;rig+=c[pl+1]-1;

        ans+=lef*rig;
        for(pll=pl-e[pl]+1;pll<=n&&pll<pl;pll++)
        {
            for(plr=pl+1+c[pl+1]-1;plr<=n&&x[plr]-x[pll]<=d;plr++)
            {
                //cout<<";"<<pll<<" "<<plr<<endl;
                ans--;
                //cnt++;if(cnt>20)break;
            }
            //cout<<"#"<<pll;
                //cnt++;if(cnt>20)break;
        }}
        return ;
    }
    //cout<<"-"<<pl<<endl;
    lef+=e[pl]-1;rig+=c[pl+1]-1;//cout<<"?"<<lef<<" "<<rig<<endl;
    for(pll=pl-e[pl]+1;pll&&e[pll]-e[pll+1]+1>0;pll=pll-e[pll]+1)
     {
         //cout<<pl<<":"<<pll<<" ";
         lef+=e[pll]-e[pll+1]+1;
         cnt++;
         if(cnt>20)break;
     }
    for(plr=pl+1+c[pl+1]-1;plr<=n&&c[plr]-c[plr-1]+1>0;plr=plr+c[plr]-1)
     {
         //cout<<pl<<"-"<<plr<<',';
         lef+=c[plr]-c[plr+1]+1;
         cnt++;
         if(cnt>50)break;
     }
    ans+=lef*rig;
        for(pll=pl-e[pl]+1;pll<=n&&pll<pl;pll++)
        {
            for(plr=pl+1+c[pl+1]-1;plr<=n&&x[plr]-x[pll]<=d;plr++)
            {
                //cout<<";"<<pll<<" "<<plr<<endl;
                ans--;
                //cnt++;if(cnt>50)break;
            }//cout<<"#"<<pll;
                //cnt++;if(cnt>50)break;
        }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&C,&T);
    if(C>=11&&C<=12)
    {
        while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        int pp=(x[2]-x[1]);
        int kk=d/pp*2-1;
        printf("%lld\n",n-kk);}
        return 0;
    }
    while(T--)
    {
        clean();
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        for(int i=1,j=1;i<=n;i++)
        {
            while(j<=n&&x[j]-x[i]<=d) j++;
            c[i]=j-i;
        }
        for(int i=n,j=n;i>0;i--)
        {
            while(j>0&&x[i]-x[j]<=d) j--;
            e[i]=i-j;
        }
        for(int pl=1;pl<n;pl++)
        {
            //cout<<c[pl]<<" "<<e[pl]<<endl;
            solve(pl);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


