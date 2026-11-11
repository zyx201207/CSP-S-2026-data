#include<bits/stdc++.h>
using namespace std;
long long d,x[2000010];
int n,tl[2000010],tr[2000010],b[2010][2010];
int sizl[2000010],sizr[2000010];
long long ans;
void solve(){
    ans=0;
    for(int i=0;i<=n+1;i++)sizl[i]=sizr[i]=0,tl[i]=tr[i]=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1,t=1;i<n;i++){
        t=max(t,i);
        while(t<n&&x[t+1]-x[i]<=d)t++;
        tl[i]=t;
        sizl[i]++;
        if(i!=t){
            if(i-1&&tl[i-1]==tl[i])sizl[t]++;
            else sizl[t]+=sizl[i];
        }
        //cerr<<"tl "<<i<<' '<<tl[i]<<' '<<sizl[i]<<'\n';
    }
    for(int i=n,t=n;i>1;i--){
        t=min(t,i);
        while(t>1&&x[i]-x[t-1]<=d)t--;
        tr[i]=t;
        sizr[i]++;
        if(i!=t){
            if(i+1<=n&&tr[i+1]==tr[i])sizr[t]++;
            else sizr[t]+=sizr[i];
        }
        //cerr<<"tr "<<i<<' '<<tr[i]<<' '<<sizr[i]<<'\n';
    }
    // for(int i=1;i<=n;i++)
    //     for(int j=i+1;j<=n;j++)
    //         if(x[j]-x[i]<=d)
    //             cerr<<i<<' '<<j<<' '<<x[j]-x[i]<<'\n';

    // for(int i=1;i<n;i++){
    //     int x=tl[i],y=tl[x];
    //     if(tr[tr[y]]==i)cerr<<"# "<<i<<' '<<y<<' '<<tr[tr[y]]<<' '<<tr[y]<<' '<<tl[i]<<'\n';
    //     if(tr[tr[y]]==i&&(tr[y]==tl[i]-1)){//>2 step
    //         ans+=1ll*sizl[i]*sizr[y]-1;
    //         cerr<<"* "<<i<<' '<<sizl[i]*sizr[y]-1<<'\n';
    //     }
    //     if(1){//=2 step
    //         int p=tl[i]-1;
    //         if(p==i)continue;
    //         p=tl[p];
    //         int q=tl[i]-2;
    //         q=tl[q];
    //         ans+=p-q;
    //         for(int j=q+1;j<=p;j++)
    //             cerr<<"% "<<i<<' '<<j<<'\n';
    //     }
    // }
    for(int i=2;i<n-1;i++){
        if(tr[i+1]>=i||tl[i]<=i+1)continue;
        int pl=tr[i+1],pr=tl[i];
        int ql=tr[i+2],qr=tl[i-1];
        if(pl==ql||pr==qr)continue;
        ans+=1ll*(ql-pl)*(pr-qr);
        if(tl[i+1]==tl[i])ans+=1ll*(ql-pl)*(sizr[pr]-1);
        if(tr[i+1]==tr[i])ans+=1ll*(sizl[pl]-1)*(pr-qr);
        if(tr[i+1]==tr[i]&&tl[i+1]==tl[i])ans+=1ll*(sizl[pl]-1)*(sizr[pr]-1);
        //if(n<=10)cerr<<"* ("<<pl<<','<<ql-1<<") ("<<qr+1<<','<<pr<<")  "<<sizl[pl]<<' '<<sizr[pr]<< '\n';
    }
    //cerr<<"end"<<'\n';
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //freopen("a.err","w",stderr);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--)solve();
    return 0;
}