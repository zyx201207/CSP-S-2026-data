#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int x,y,l=1,ans=1,d=0,k=0;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        cin>>a[i];
        if(i!=1&&a[i]<a[i-1]){
            k=1;
        }
    }
    if(k){
        sort(a+1,a+x+1);
    }
    for(int i=1;i<=x;i++){
        if(i!=1){
            d+=(i-l)*(a[i]-a[i-1]);
        }
        while(d>y){
            l++;
            d-=a[i]-a[l-1];
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
