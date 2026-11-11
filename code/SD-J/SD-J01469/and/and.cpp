#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=200005;
int n,m,lpl[N],ans,w[35];
bool f[N],q,e;
void dfs(int dep,int sum){
	if(dep>=m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(dep+1,(sum&lpl[i]));
			f[i]=0;
		}
	}
}
	signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int zxr=1;
	for(int i=0;i<=21;i++){
		w[i]=zxr;
		zxr*=2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lpl[i];
		bool r=0;
		for(int j=1;w[j]<=lpl[i];j++){
			if(lpl[i]==w[j]-1){
				r=1;
				break;
			}
		}
		if(!r){
			e=1;
		}
		if(lpl[i]!=i-1){
			q=1;
		}
	}
	if(!q){
		cout<<n-m;
		return 0;
	}
	sort(lpl+1,lpl+n+1);
	if(!e){
		cout<<lpl[n-m+1];
		return 0;
	}
	if(m==1){
		cout<<lpl[n];
		return 0;
	}
	if(m==n){
		int ans=lpl[1];
		for(int i=2;i<=n;i++){
			ans=(ans&lpl[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(lpl[i]&lpl[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(1,lpl[i]);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
