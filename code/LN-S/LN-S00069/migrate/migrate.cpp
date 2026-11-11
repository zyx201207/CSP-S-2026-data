#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
int q(int x,int y,int z){
	for(int i=x+1;i<=y;i++)if(a[i]-a[i-1]>z)return 0;
	return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n-3;i++){
			if(q(i,i+3,d))ans++;
        }cout<<ans<<endl;
    }
    return 0;
}
