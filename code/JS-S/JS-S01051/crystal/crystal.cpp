#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,ans=INT_MIN;
long long m,a[maxn],b[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    b[2]=a[2]-a[1];
    for(int i=3;i<=n;i++) b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    for(int j=2;j<=n;j++){
        if(b[j]<=m) ans=max(ans,j);
        else break;
    }
    for(int i=2;i<n;i++){
        for(int j=i+1;j<=n;j++){
            long long t=b[j]-b[i]-(i-1)*(a[j]-a[i]);
            if(t<=m) ans=max(ans,j-i+1);
            else break;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
