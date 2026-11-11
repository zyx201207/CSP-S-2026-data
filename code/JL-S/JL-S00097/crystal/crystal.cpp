#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
bool check(int num){
    int h=0;
    for(int i=1;i<num;i++){
        h+=a[num]-a[i];
    }
    if(h<=m) return 1;
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n,mid,res=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
           res=mid;
           l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<res;
    return 0;
}
