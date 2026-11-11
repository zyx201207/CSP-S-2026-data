#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
const int mod=998244353;
const int inf=1e18;
int n,d;
int a[N];
int tot[N];
int point;
int mmin=1e18;
int sum=0;
void dfs(int dep,int ed){
	if(dep==ed){
		tot[++point]=a[dep];
		dfs(dep+1,ed);
	}
	if(dep==ed+1){
		for(int i=2;i<=point;i++){
			if(tot[i]-tot[i-1]>d) return;
			if(point-1<mmin){
				mmin=point-1;
				sum=1;
			}else if(point==mmin){
				sum++;
			}
		}
		
	
		return;
	}
	tot[++point]=a[dep];
	dfs(dep+1,ed);
	point--;
	dfs(dep+1,ed);
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				mmin=1e18;
				point=0;
				sum=0;
				tot[1]=a[i];
				dfs(i+1,j);
				if(sum==2){
					ans++;
					cout<<i<<" "<<j<<"\n";
					
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
