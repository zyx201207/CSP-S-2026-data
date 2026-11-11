#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n],b[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=32;i>=0;i--){
        int x=1ll<<i,cnt=0;
        for(int j=0;j<n;j++){
            if(b[j]==0&&a[j]>=x){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=x;
        }
        for(int j=0;j<n;j++){
            if(b[j]==0){
                if(a[j]>=x){
                    a[j]-=x;
                }else if(cnt>=m){
                    b[j]=1;
                }
            }
        }
    }
    cout<<ans;
}
//100~100
