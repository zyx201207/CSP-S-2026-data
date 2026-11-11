#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+34;
ll n,m,ans;
ll a[N];
bool vis[N];
void dfs(ll sum,ll s,ll p){
	if(n-p+s<m)return;
	if(s==m){
		for(int i=p;i<=n;i++){
			ans=max(ans,sum&a[i]);
		}
		return;
	}else{
		for(int i=p+1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(sum&a[i],s+1,i);
				vis[i]=0;
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);	
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[i]=0;
			vis[i]=1;
			dfs(a[i],1,i);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
