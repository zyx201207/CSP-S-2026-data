#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],cf[N],cf1[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        cf[i]=cf[i-1]+a[i];
    }
    for (int i=n;i>=1;i--){
        cf1[i]=cf1[i+1]+a[i];
    }
    int ans=0,ans1=0;
    for (int j=1;j<=n;j++){
    for (int i=j+1;i<=n;i++){
        int c=(i-1)*a[i]-cf[i-1];
        if (c<=m){
            ans=i;
        }
        else break;
    }
    ans=max(ans1,ans);
    ans1=ans;
    }
    cout<<ans;
    return 0;
}
