#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int maxx=-1e9;
void dfs(int ii,int ans){
	int cnt=1;
	for(int i=ii+1;i<=n;i++){
		if(ans>m)break;
		if(ans<=m){
			cnt=i-ii+1;
		}
		int t=abs(a[i]-a[i-1]);
		ans+=t*(i-ii+1);
		//cout<<ans<<" "<<cnt<<" "<<a[i]<<'\n';
	}
	maxx=max(cnt,maxx);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=1;
	}
	sort(a+1,a+1+n);
	if(m==0){
		int u=a[1];
		int ans=0;
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			if(u==a[i]){
				ans++;
			}
			else if(u!=a[i]){
				maxx=max(maxx,ans);
				ans=1;
				u=a[i];
			}
		}
		cout<<maxx;
	}
	else{
		if(f==0){//特殊性质A 
			int ans=0;
			for(int i=1;i<n;i++){
				if(ans>m){
					cout<<i-1;
					return 0;
				}
				ans+=i;
			}
			cout<<n;
		}
		else{
			int w=a[2]-a[1];
			f=0;
			for(int i=1;i<n;i++){
				if(a[i]+w!=a[i+1]){
					f=1;
				}
			}
			if(f==0){//特殊性质B 
				int ans=0;
				for(int i=1;i<n;i++){
					if(ans>m){
						cout<<i-1;
						return 0;
					}
					ans=ans+w*i;
				}
				cout<<n;
			}
			else{
				for(int i=1;i<=n;i++){
					dfs(i,0);
				}
				cout<<maxx;
			}
		}
	}
	return 0;
}
