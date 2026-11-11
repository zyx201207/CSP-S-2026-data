#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int n,ans;
ll m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int sum=1;
    for(int i=2;i<=n;i++){
        sum=1;
        if(i-ans+1<1) continue;
        for(int j=i-ans+1;j>=1;j--){
            if(1ll*(i-j+1)*a[i]-(pre[i]-pre[j-1])<=m) sum=i-j+1;
            else break;
        }ans=max(ans,sum);
    }cout<<ans;
    return 0;
}