#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001],n,m,c[200001][31];
pair<int,int>g[200001];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second>y.second;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],t=0;
		while(x){
			c[i][t]=x%2;
			t++;
			x/=2;
		}
		g[i].first=a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=c[j][i];
		} 
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(c[j][i]){
					g[j].second+=pow(2,i);
				}
			}
		}
	}
	sort(g+1,g+1+n,cmp);
	int ans=g[1].first;
	for(int i=2;i<=m;i++){
		ans&=g[i].first;
	}
	cout<<ans;
	return 0;
}
