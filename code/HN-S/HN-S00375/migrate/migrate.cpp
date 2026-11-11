#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,d,a[N];
void solve1(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int dx=a[2]-a[1];
    if(d<2*dx)cout<<"0\n";
    else cout<<max(0ll,n-(d/dx)*2+1)<<"\n";
}
int rr[N];
void solve2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i],rr[i]=0;
    sort(a+1,a+n+1);
    int pos=1;
    for(int i=1;i<=n;i++){
        while(pos<n&&a[pos+1]-a[i]<=d)pos++;
        rr[pos]++;
    }
    pos=n;
    int ans=-0;
    for(int i=n;i>=1;i--){
        while(pos>1&&a[i]-a[pos-1]<=d)pos--;
        ans+=rr[pos+1];
    }
    cout<<ans<<"\n";
}
int pre[N],suf[N];
bool check(int l,int r){
    pre[l]=0;
    int lst=l;
    for(int i=l+1;i<=r;i++){
        pre[i]=pre[lst]+1;
        if((a[i]-a[lst])>d)pre[i]++,lst=i;
    }
    suf[r]=0,lst=r;
    for(int i=r-1;i>=l;i--){
        suf[i]=suf[lst]+1;
        if((a[lst]-a[i])>d)suf[i]++,lst=i;
    }
    int mn=n,sum=0;
    for(int i=l;i<=r;i++)
        mn=min(mn,pre[i]+suf[i]);
    for(int i=l+1;i<r;i++)
        if(pre[i]+suf[i]==mn)
            sum++;
    return sum==2;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(check(i,j))ans++;
        }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int cid,T;cin>>cid>>T;
    while(T--)
        if(cid==11||cid==12)solve1();
        else if(cid==13||cid==14)solve2();
        else solve();
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/