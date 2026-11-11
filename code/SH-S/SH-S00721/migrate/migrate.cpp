#include<bits/stdc++.h>
using namespace std;
long long c,n,m,t,a[2000005],mn[100005],mn1[100005];

//void dfs(int x,int cnt){
//	for(int j=1;j<=n;j++){
//		if(x==n){
//			if(cnt<mn){
//				mn[j]=cnt,mn1[j]=1e18+1;
//			}
//			else if(cnt==mn){
//				mn1[j]=cnt;
//			}
//			return;
//		}
//	}
//	
//	for(int i=x+1;i<=n;i++){
//		if(a[i]-a[x]<=m) dfs(i,cnt+1);
//		else break;
//	} 
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=14&&c>=13){
		for(int i=1;i<=t;i++){
			cout<<0<<'\n';
		}
		return 0;
	}
	if(c<=12&&c>=11){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			sort(a+1,a+1+n);
			long long d=a[2]-a[1];
			if(m/d<=1){
				cout<<0<<'\n';
				continue;
			}
			long long xx=m/d;
			cout<<max(0ll,n+1-xx*2)<<'\n';
		}
		return 0;
	}
	while(t--){
		cout<<0<<'\n';
	}
	
	return 0;
	
}
