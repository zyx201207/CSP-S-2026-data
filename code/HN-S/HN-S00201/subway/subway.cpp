#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}s[1005];
int c,n,m,d,q,w[200005],k[200005],x,y,dp[1005][1005],tt[1005],cntt;
vector<int,int> a[1005],t[1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cntt=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			if(tt[x]){
				dp[++cntt][x]=y;
				dp[c][cntt]=y;
				if(tt[x]==1){
					dp[cntt][s[x].x]=s[x].y;
					dp[s[x].x][cntt]=s[x].y;
				}
				tt[x]++; 
			}
			else{
				s[x].x=x,
			}
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70 70 33
*/
