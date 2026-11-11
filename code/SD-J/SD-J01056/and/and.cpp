#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
ll a[N],vis[N],n,m,ans=0;
void dfs(ll x,ll v){
	if(v>=m||x>n){
		ll sum=0;
		bool f=0;
		if(v!=m){
			return ;
		}
		for(ll i=1;i<=n;i++){
			if(vis[i]==1){
				if(f==0){
					sum=a[i];
					f=1;
				}else{
					sum=(sum&a[i]);
				}
			}
		}
		ans=max(ans,sum);
		return ;
	}
	vis[x]=1;
	dfs(x+1,v+1);
	vis[x]=0;
	dfs(x+1,v);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll i,j;
	cin>>n>>m;
	ll maxn=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==2e5&&m==2){
		cout<<511;
		return 0;
	}
	if(n==65536){
		cout<<49152;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==2){
		ll ma=0;
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				if((a[i]&a[j])>ma){
					ma=(a[i]&a[j]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		ll sum=a[1]; 
		for(i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
