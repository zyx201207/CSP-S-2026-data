#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5;
int n,ans;
int a[N+10];
char c[N+10];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]) ans+=min(a[l],a[r]);
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r]){
            l++;
            r--;
        }
        else{
            a[r]-=a[l];
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
