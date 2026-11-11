#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+3;
ll a[N],c,t,n,d;
ll dfs(int u,int v){
	if(u==v) return 1;
	ll res=0;
	for(int i=1;i<=n;i++){
		if(a[u+i]-a[u]<=d) res+=dfs(u+i,v);
		else break;
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool f=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=false;
		}
		if(f){
			cout<<n-d*2+1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
