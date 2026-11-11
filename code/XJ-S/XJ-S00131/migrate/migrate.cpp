#include<bits/stdc++.h>
using namespace std;
map<pair<long long,long long>,long long> mp;
long long zx[5005][5005],arr[2000005];
long long c,T,n,d;
long long zd(long long x,long long y){
	long long zb=arr[x];
	long long ans=0;
	while(1){
		ans++;
		if(zb+d>=arr[y]){
			return ans;
		}
		zb=*lower_bound(arr+1,arr+1+n,zb+d);
	}
}
vector<long long> gj;
void dfs(long long mq){
	if(mq>n){
		return ;
	}
	gj.push_back(mq);
	if(zx[*gj.begin()][*(gj.end()-1)]<gj.size()-1){
		gj.pop_back();
		return ;
	}
	mp[{*gj.begin(),*(gj.end()-1)}]++;
	for(long long i=mq;i<=n;i++){
		if(arr[i]-arr[mq]<=d){
			dfs(i);
		}
	}	
	gj.pop_back();
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=0;i<5005;i++){
			for(int j=0;j<5005;j++){
				zx[i][j]=0;
			}
		}
		mp.clear();
		gj.clear();
		for(long long i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				zx[i][j]=zd(i,j);
			}
		}
		for(long long i=1;i<=n;i++){
			dfs(i);
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(mp[{i,j}]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}

