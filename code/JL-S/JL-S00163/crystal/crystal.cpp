#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],b[500010];
bool check(int x,int w){
    if(a[w]*(w-x+1)-(b[w]-b[x-1])<=m) return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    b[i]=b[i-1]+a[i];
    int l=1,r=i;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,i)) r=mid-1,ans=max(ans,i-mid+1);
        else l=mid+1;
    }
}
cout<<ans;
return 0;
}
