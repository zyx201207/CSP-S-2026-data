#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d;
int a[2000010],dp[2000010],g[2000010],s[2000010];
int nxt[2000010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int x=1;x<=n;x++){
            cin>>a[x];
        }
        /*
        if(n<=0){
            int ans=0;
            for(int x=1;x<=n;x++){
                int l=a[x],ss=0;
                //cout<<x<<'\n';
                for(int y=x+1;y<=n;y++){
                    if(a[y]-a[y-1]>d)break;
                    if(a[y]>l){
                        ss++;
                        l=a[y-1]+d;
                    }
                    g[y]=ss;
                }
                l=x;
                s[x-1]=0,s[x]=1;
                int r=x;
                for(int y=x+1;y<=n;y++){
                    if(a[y]-a[y-1]>d)break;
                    if(g[y]>g[y-1])r=y-1;
                    while(a[y]-d>a[l])l++;
                    dp[y]=s[r]-s[l-1];
                    if(dp[y]>3)dp[y]=3;
                    if(dp[y]==2)ans++;
                    s[y]=s[y-1]+dp[y];
                }
            }
            cout<<ans<<'\n';
            continue;
        }*/
        int r=n,ans=0;
        nxt[n]=n;
        for(int x=n-1;x>=1;x--){
            while(a[x]+d<a[r])r--;
            nxt[x]=r;//处理出父亲
            //if(nxt[x]!=nxt[x+1])cout<<x<<'\n';
        }
        for(int x=n;x>=1;x--){
            int r=0;//记录最右边的dp值是2的位置
            int h=0;//记录最右边的dp值>2的位置
            int len=1;
            dp[x]=1;
            //cout<<x<<'\n';
            int anss=ans;
            for(int y=x;;){
                int z=nxt[y];
                if(z==y)break;
                dp[z]=dp[y];
                if(dp[y]==1){
                    if(len==1)dp[z]=dp[y];
                    else if(len==2){
                        //先更新r和h标记
                        int rr=r,hh=h;
                        if(nxt[h]<=y)h=0;
                        else h=nxt[h];
                        int pp=nxt[r];
                        if(pp>y)h=max(h,pp);
                        r=0;
                        //然后记录新的标记
                        int p1=y-1,op=0;
                        if(rr==p1)op=1;
                        p1=nxt[p1];
                        if(p1>y){
                            if(op==1)h=max(h,p1);
                            else r=max(r,p1);
                        }
                        ans+=max(0ll,r-max(h,y));
                        if(r==z)dp[z]=2;
                        if(h==z)dp[z]=3;
                    }
                    else{
                        //len>2
                        int rr=r,hh=h;
                        if(nxt[h]<=y)h=0;
                        else h=nxt[h];
                        int pp=nxt[r];
                        if(pp>y)h=max(h,pp);
                        r=0;

                        int p1=y-1,op=0;
                        if(rr==p1)op=1;
                        p1=nxt[p1];
                        if(p1>y){
                            if(op==1)h=max(h,p1);
                            else r=max(r,p1);
                        }
                        p1=y-2;
                        if(nxt[p1]>y)h=max(h,nxt[p1]);
                        ans+=max(0ll,r-max(h,y));
                        if(r==z)dp[z]=2;
                        if(h==z)dp[z]=3;
                    }
                }
                else if(dp[y]==2){
                    if(len==1)dp[z]=dp[y],ans+=z-y;
                    else{
                        int p1=y-1;
                        if(nxt[p1]>y)h=max(h,nxt[p1]);
                        ans+=max(0ll,z-max(h,y));
                        if(h==z)dp[z]=3;
                    }
                }
                else break;
                len=z-y;
                y=z;
                //cout<<z<<' '<<dp[z]<<' '<<r<<' '<<h<<' '<<ans<<'\n';
            }
        }
        cout<<ans<<'\n';
        /*
        
        //4：15还不会就跳题
        //4：13会性质C了，试试吧，3年还没有一个T3会做。
        //C性质通过，怎么优化呢？
        //不会，跳了
        //现在4年了
        //不过对于一个退役选手来说，也无所谓了。
        //最后的CSP了，整点活吧
        //ZyCwoxihuanni
        */
    }
}
/*
*/