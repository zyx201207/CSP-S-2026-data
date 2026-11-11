#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],vis[N];int n,d,minn=1e9;
map<int,int> mp;
struct node{
	int v,w;
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		vector<int> vec[100000];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[i]=0;
		}
		if(a[2]-a[1]==a[3]-a[2]&&a[4]-a[3]==a[3]-a[2]&&a[5]-a[4]==a[4]-a[3]){
			d/=(a[2]-a[1]);
			if(d==1){
				cout<<0;
				continue;
			}
			cout<<max(0ll,n-(d+d-1))<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					mp[k]=0;
					vis[k]=0;
				}
				minn=1e18;
				queue<node> q;
				q.push({i,0});
				while(q.size()){
					node s=q.front();
					q.pop();
					if(s.v==j){
						mp[s.w]++;
						minn=min(minn,s.w);
					}
					if(vis[s.v]) continue;
					vis[s.v]=1;
					for(auto z:vec[s.v]){
						q.push({z,s.w+1});
					}
				}
				cout<<mp[minn]<<' ';
				if(mp[minn]==2){
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

