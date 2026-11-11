#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define st string
#define db double
#define ch char
#define bo bool
#define s2 505
#define s3 5005
#define s4 50005
#define s5 500005
#define s6 1000005
#define s7 10000005
using namespace std;
int a[s5],d[s5],n,m,ans=1;
int check(int x,int y,int z){
    int t=z-x+1;
    t*=y;
    if(t-(d[z]-d[x-1])<=m) return 1;
    else return 0;
}
int solve(int x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid,a[x],x)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return x-l+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}
