#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005],a[1000005],mx,sum;
void dfs(int d,int f,int sum,int a){
	if(d==f){
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<n;i++){
		if(u[i]==d && i!=a) dfs(v[i],f,sum+1,i);
		if(v[i]==d && i!=a) dfs(u[i],f,sum+1,i);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		mx=-2e9;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dfs(i,j,0,i);
				a[i]=mx;
			}
		}
		sort(a+1,a+n+1);
		cout<<a[k]<<"\n";
	}
	return 0;
}
