#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int x[N],ans,a[N];
bool check(int x,int y){
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		if(n<4){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int l=4;l<=n;l++){//lenth
			for(int i=1;i<=n;i++){
				if(check(i,i+l))ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
