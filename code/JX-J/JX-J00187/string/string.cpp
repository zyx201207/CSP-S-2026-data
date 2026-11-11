#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
char c[1000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int x,ans=0;
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=x;
    while(r>l){
        int k=min(a[r],a[l]);
        if(c[r]!=c[l]){
            ans+=k;

        }
        a[r]-=k;
        a[l]-=k;
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
