#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500005],f,jl,ans;

void dfs(ll x,ll cnt,ll b[]){
	if(cnt==m){
		map<ll,ll> vis;
		for(int i=1;i<=n;i++){
			vis[b[i]]++;
			ans = max(vis[b[i]],ans);
//			cout << b[i] << " ";
		}
//		cout << endl;
		return ;
	}
	if(x==n+1){
		return ;
	}
	int ls = b[x];
	for(int i=0;i<=m-cnt;i++){
		dfs(x+1,cnt+i,b);
		b[x]++;
	}
	b[x] = ls;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i>1){
			if(i==2){
				jl = a[i]-a[i-1];
			}
			else if(jl!=(a[i]-a[i-1])){
				f = 1;
			}
		}
	}
	if(!f){
		ll gc = sqrt((m*8.0+jl*1.0)/(jl*4.0))-0.5;
		/*gc += jl;
		gc /= 4*jl;
		gc = sqrt(gc);
		gc -= 0.5;*/
		cout << gc+1;
		return 0;
	}
	dfs(1,0,a);
	cout << ans;
	return 0;
}
