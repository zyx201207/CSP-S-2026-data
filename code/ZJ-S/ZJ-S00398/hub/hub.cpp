#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	int i,j;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		vector<int>ve[1010];
		int n,m,dp[1010],ndp[1010],pdp[1010];cin>>n>>m;
		int de[1010];
		memset(dp,0x3f,sizeof(dp));
		memset(ndp,0x3f,sizeof(ndp));
		memset(de,0,sizeof(de));
		memset(pdp,0x3f,sizeof(pdp));
		for(i=1;i<n;i++){
			int x,y;cin>>x>>y;
			ve[x].push_back(y);
			ve[y].push_back(x);
		}int dee=2e9;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(de[j])continue;
				for(int di=1;di<=n;di++)ndp[di]=dp[di];
				queue<int>q;q.push(j);ndp[j]=0;
				while(!q.empty()){
					int p=q.front();q.pop();
					for(auto it:ve[p]){
						int nd=ndp[p]+1;
						if(ndp[it]>nd){
							ndp[it]=nd;
							q.push(it);
						}
					}
				}int lee=0;
				for(int di=1;di<=n;di++)lee=max(lee,ndp[di]);
				if(lee<dee){
					dee=lee;
					for(int di=1;di<=n;di++)pdp[di]=ndp[di];
				}
			}
			for(j=1;j<=n;j++)dp[j]=pdp[j];
		}
		cout<<dee<<endl;
	}
	return 0;
}

