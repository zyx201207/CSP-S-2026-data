#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],sum=0;
bool vis[2000005];
bool check(int u,int v){
	queue<pair<int,int> > q;
	q.push({u,0});
	vector<long long> vec;
	while(!q.empty()){
		int now=q.front().first;
		int t=q.front().second;
		q.pop();
		if(now==v){
			vec.push_back(t);
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==false){
				vis[i]=true;
				q.push({i,t});
			}
		}
		long long cnt=0,len=vec.size(),minn=0x3f3f3f3f;
		for(int i=0;i<len;i++){
			if(minn=vec[i]){
				cnt++;
			}
			minn=min(minn,vec[i]);
		}
		if(cnt==2){
			return true;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
