#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,a[N],ans;
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n,p=1;
    while(l<r){
        int mng=min(a[l],a[r]);
        if(c[l]!=c[r]){
            ans+=mng;
        }
        a[l]-=mng;
        a[r]-=mng;
        if(!a[l]){
            l++;
        }
        if(!a[r]){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
