#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,a[2000005],n,d;
bool vis[2005][2005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        if(a[i+2]-a[i]<=d)
        vis[i][i+2]=1;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
            if((a[j]-a[i])>d&&(j-i-1)==2&&vis[i][i+2]==1&&vis[i+1][i+3]==1){	
			ans++;
		}
		}
	}
	cout<<ans<<endl;
}
return 0;
}
