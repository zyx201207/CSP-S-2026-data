#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int a[n];char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n-1,ans=0;
    for(;l<r;){
        if(a[l]==a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            l++;r--;
        }else{
            if(a[l]>a[r]){
                if(c[l]!=c[r]){
                    ans+=a[r];
                }
                a[l]-=a[r];
                r--;
            }else{
                if(c[l]!=c[r]){
                    ans+=a[l];
                }
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
}
//100~100
