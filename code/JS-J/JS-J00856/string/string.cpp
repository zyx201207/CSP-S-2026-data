#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200006;
int a[N];
char c[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    int ans=0;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]==a[r]){
            l++,r--;
        }
        else{
            if(a[l]<a[r]) a[r]-=a[l++];
            else a[l]-=a[r--];
        }
    }
    cout<<ans;
    return 0;
}