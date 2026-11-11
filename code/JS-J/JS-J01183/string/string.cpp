#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    int ans=0;
    while(l<r){
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        //cout<<a[l]<<" "<<a[r]<<" "<<c[l]<<" "<<c[r]<<endl;
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }
        else{
            l++;
            r--;
        }
        //cout<<a[l]<<" "<<a[r]<<" "<<c[l]<<" "<<c[r]<<endl;
    }
    cout<<ans;
    return 0;
}
