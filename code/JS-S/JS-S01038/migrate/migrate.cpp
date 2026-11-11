#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define y0 y000
#define y1 y111
#define j0 j000
#define j1 j111
typedef long long ll;
typedef unsigned long long ull;
int nxt[2000006],lst[2000006];
ll arr[2000006];
int dp[2000006][8];
int to_st[4][4];
pii st_to[7];
int calc(int i,int j,int k,int a,int b){
    if(lst[k]==j)return b;
    else if(lst[k]==j-1)return min(a+b,3);
    else return (a==0?b:3);
}
pii trs(int i,int j,int k,int s){
    int a=st_to[s].fi,b=st_to[s].se;
    int na=0,nb=calc(i,j,k,a,b);
    if(k>j+1)na=calc(i,j,k-1,a,b);
    int r2=0;
    if(b==2)r2+=nxt[j]-nxt[j-1];
    if(a==1&&b==1&&j>=2)r2+=nxt[j-1]-nxt[j-2];
    return mkp(r2,to_st[na][nb]);
}
int sm=0;
void slv(){
    int n;ll d;
    cin>>n>>d;
    sm+=n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int j=1;
    for(int i=1;i<=n;i++){
        while(j<=n&&arr[j]-arr[i]<=d)j++;
        nxt[i]=j-1;
    }
    j=n;
    for(int i=n;i>=1;i--){
        while(j>=1&&arr[i]-arr[j]<=d)j--;
        lst[i]=j+1;
    }
    for(int i=0;i<=n;i++)memset(dp[i],0,sizeof(dp[i]));
    // for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';
    // cout<<'\n';
    for(int i=n;i>=1;i--){
        if(nxt[i]==i)continue;
        for(int j=0;j<7;j++){
            pii s=trs(lst[i],i,nxt[i],j);
            dp[i][j]=dp[nxt[i]][s.se]+s.fi;
        }
    }
    // for(int i=1;i<=n;i++){
        // cout<<i<<' '<<nxt[i]<<':';
        // for(int j=0;j<7;j++)cout<<dp[i][j]<<' ';
        // cout<<'\n';
    // }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=dp[i][0];
    cout<<ans<<'\n';
}
int main(){
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)to_st[i][j]=7;
    to_st[0][1]=0;to_st[0][2]=1;to_st[1][1]=2;to_st[2][1]=3;to_st[2][2]=4;to_st[3][1]=5;to_st[3][2]=6;
    st_to[0]=mkp(0,1);
    st_to[1]=mkp(0,2);
    st_to[2]=mkp(1,1);
    st_to[3]=mkp(2,1);
    st_to[4]=mkp(2,2);
    st_to[5]=mkp(3,1);
    st_to[6]=mkp(3,2);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,tc;
    cin>>c>>tc;
    while(tc--)slv();
    return 0;
}
//peimuda bless me
//MatrixGroup bless me
//hyman00 bless me
//UKBwyx bless me
//luckyclover bless me
//He_XY bless me
//daisybunny bless me
//chenmohan bless me
//xuanxuanni bless me
//Tk_hash bless me
//chennie bless me
//placeholder bless me
//Cubber bless me
//rp++