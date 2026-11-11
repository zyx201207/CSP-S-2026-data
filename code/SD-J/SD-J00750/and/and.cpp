#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
bool f[200010];
ll a[200010],ans,sum,maxn,maa; 
void dfs(ll i,ll cnt,ll sol){
	if(cnt==m){
		maa=max(maa,sol);
		return;
	}
	if(i>=n+1) return;
	dfs(i+1,cnt+1,sol&a[i+1]);
	dfs(i+1,cnt,sol);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum=a[1];
		sum&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		ll res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				res=max(res,a[i]&a[j]);
			}
		}
		cout<<res;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(0,0,INT_MAX);
		cout<<maa;
		return 0;
	}
	for(int i=32;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]==0&&(a[j]>>i)&1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(f[j]==0&&!(a[j]>>i)&1){
					f[j]=1;  
				}
			}
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
