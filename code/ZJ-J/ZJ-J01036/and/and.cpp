#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f=1;
int a[200010],v[4];
void dfs(int x,int t,int add){
	if(t==m){
		ans=max(ans,add);
		return;
	}
	if(x>n) return;
	dfs(x+1,t,add);
	dfs(x+1,t+1,add&a[x]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) f=0;
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,INT_MAX);
		cout<<ans;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(a[n]<4){
		for(int i=1;i<=n;i++){
			v[a[i]]++;
		}
		if(v[3]>=m) cout<<3;
		else if(v[3]+v[2]>=m) cout<<2;
		else if(v[3]+v[1]>=m) cout<<1;
		else cout<<0;
	}
	else if(f==1){
		int x=n/2;
		while(x>=m){
			ans+=x;
			x/=2;
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else cout<<a[n-m+1];
}