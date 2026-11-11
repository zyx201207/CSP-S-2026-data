#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1],k[n];
	for(int j=1;j<=m;j++){
		cin>>w[j];
	}
	int a[n+1][500005],t[m+1][500005];
	vector<pair<int,int> > v[m+1];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[a[i][j]][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int k=1;k<j;k++){
				v[a[i][j]].push_back(make_pair(a[i][k],t[a[i][j]][i]+t[a[i][k]][i]));
				v[a[i][k]].push_back(make_pair(a[i][j],t[a[i][j]][i]+t[a[i][k]][i]));
			}
		}
	}
	vector<pair<int,int> > r(q+1);
	for(int ri=1;ri<=q;ri++){
		int x,y;
		cin>>x>>y;
		r[ri]=make_pair(x,y);
	}
	/**/
	int dp[m];
	memset(dp,0,sizeof(dp));
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int ri=1;ri<=q;ri++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=v[ri].size();j++){
			pq.push(make_pair(r[ri].first,j));
		}
		while(!pq.empty()){
			int s=pq.top().first,e=pq.top().second;
			if(s==r[ri].second){
				cout<<dp[s]+w[r[ri].first]+w[r[ri].second]<<endl;
				break;
			}
			dp[v[s][e].first]=max(dp[v[s][e].first],dp[s]+v[s][e].second);
			for(int j=1;j<=v[v[s][e].first].size();j++){
				pq.push(make_pair(r[v[s][e].first].first,j));
			}
		}
	}
	return 0;
} 