#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
int n,m,a[N];
int ans=-0x3f3f3f3f;
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(m==1){
            ans=max(ans,a[i]);
            return 0;
        }
    }
    for(int i=1;i<=n-m+1;i++){
        for(int j=i;j<=i+m;j++){
            ans=max(ans,a[i]&a[i+j]);
        }
    }
    cout<<ans;
    return 0;
}