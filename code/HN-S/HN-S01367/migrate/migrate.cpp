#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[5111],cnt,sum;
pair<int,int> f[5111][5111];
vector<int> a[5111];
void bfs(int st){
	queue<pair<int,int> > q;
	q.push({st,0});
	while(!q.empty()){
		pair<int,int> now=q.front();
		q.pop();
		for(int i=0;i<a[now.first].size();i++){sum++;
			int nex=a[now.first][i];
			if(f[st][nex].first>now.second+1)
				f[st][nex]={now.second+1,1};
			else if(f[st][nex].first==now.second+1)
				f[st][nex].second++;
			q.push({nex,now.second+1});
		}
	}
}
bool solve(){
	cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i].clear();
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)
				a[i].push_back(j);
			f[i][j]={1e18+1231231134,0};
		}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<a[i].size();j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
		bfs(i);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(f[i][j].second==2) 
				cnt++;
	cout<<cnt<<endl;
}
signed main(){
	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		solve();
		t--;
	}
	cout<<"sum="<<sum;
	return 0;
}
