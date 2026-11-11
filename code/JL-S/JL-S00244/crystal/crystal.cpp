#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    long long a[10010];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int minn=10010,beused=0;
    long long ans=0;
    while(beused<=m){
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]<=minn){
                minn=a[i+1]-a[i];
                beused+=minn;
            }
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
