#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,key,f;
int check(int x){
    bool c=0;
    long long ans=0;
    for(int j=x-1;j>=1;j--){
        ans+=a[x]-a[j];
    }
    if(ans<=m) c=1;
    for(int i=x+1;i<=n;i++){
        ans-=a[i-1]-a[i-x];
        ans+=x*(a[i]-a[i-1]);
        if(ans<=m) c=1;
    }
    if(c) return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    key=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=key) {f=1;break;}
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else r=mid-1;
    }
    cout<<l;
    return 0;
}
