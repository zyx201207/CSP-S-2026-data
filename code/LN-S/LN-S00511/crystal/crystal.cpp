#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int v[500005];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    int pre[500005];
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+v[i];
    }
    int mn=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l<r){
            int mid=(l+r)/2;
            if(v[i]*(i-mid+1)+pre[mid-1]-pre[i]>m){
                l=mid+1;
            }
            else r=mid;
        }
        mn=max(mn,i-l+1);
    }
    cout<<mn;
}