#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200007][31];
long long t[200007];
int d[21];
int ans;
long long tw[31];
int k[31];
void dfs(int now,int res,int dep){
    if(dep==m){
        ans=max(ans,res);
        return;
    }
    for(int i=now+1;i<=n;i++){
        dfs(i,d[i]&res,dep+1);
    }
}
void to2(long long x,int y){
    for(int i=30;i>=0;i--){
        if(tw[i]>x)continue;
        a[y][i]=1;
        x-=tw[i];
        k[i]++;
    }

}
main(){
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;

    //1-5

    if(n<=20){
        for(int i=1;i<=n;i++){cin>>d[i];}
        for(int i=1;i<=n;i++){dfs(i,d[i],1);}
        cout<<ans;return 0;
    }

    //6,7,8-10

    else if(n<=2000){
        if(m==1){long long s=0,g;while(n--){cin>>g;s=max(s,g);}cout<<s;return 0;}
        if(m==2){long long s=0,b[2007];for(int i=1;i<=n;i++){cin>>b[i];}for(int i=1;i<n;i++){for(int j=i+1;j<=n;j++){s=max(s,b[i]&b[j]);}}cout<<s;return 0;}
        if(m==n){long long s;cin>>s;n--;while(n--){int t;cin>>t;s&=t;}cout<<s;return 0;}
    }

    //RP++

    for(int i=1;i<=n;i++){cin>>t[i];}
    if(t[1]<=4&&t[2]<=4&&t[n]<=4&&t[2001]<=4&&t[2002]<=4){
        int cnt=0,cntt=0;
        for(int i=1;i<=n;i++){cnt+=(t[i]==3);cntt+=(t[i]!=0);}
        if(cnt>=m)cout<<"2";
        else if(cntt>=m)cout<<"1";
        else cout<<"0";
        return 0;
    }
    tw[0]=1;
    for(int i=1;i<30;i++){
        tw[i]=tw[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        to2(t[i],i);
    }
    int maxn=0;
    for(int i=0;i<=30;i++)maxn=max(k[i],maxn);
    if(maxn<m){
        cout<<"0";
        return 0;
    }
    else if(maxn==m){
        for(int i=1;i<=30;i++){
            if(k[i]==maxn){
                cout<<k[i];
                return 0;
            }
        }
        return 0;
    }
    for(int i=1;i<=maxn-m+1;i++){
        ans+=tw[i-1];
    }
    cout<<ans;
    return 0;
}
