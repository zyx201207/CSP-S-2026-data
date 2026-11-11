#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cc 500005
int a[cc],qj[cc];int n,m;
bool check(int t){
    for(int i=t;i<=n;++i){
        if(a[i]*(t-1)-qj[i-1]+qj[i-t]<=m)return 1;
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;//n=read(),m=read();
    for(int i=1;i<=n;++i)cin>>a[i];//=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        qj[i]=qj[i-1]+a[i];
        //qj1[i]=qj1[i-1]+qj[i];
    }
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){l=mid;}
        else r=mid;
        if(r-l==1){
            if(check(r))cout<<r;
            else if(check(l))cout<<l;
            break;
        }
    }

    return 0;
}
