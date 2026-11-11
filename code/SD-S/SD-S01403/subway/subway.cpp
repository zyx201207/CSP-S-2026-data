#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,w[500005]={};
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<vector<int>>a(n+1),t(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s,ti;
			cin>>s>>ti;
			a[i].push_back(s);
			t[i].push_back(ti);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,mi=1e18;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int fx=0,fy=0,xt=0,yt=0,ans=0;
			for(int j=0;j<=a[i].size();j++){
				if(a[i][j]==x){
					fx=1;
					xt=t[i][j];
				}
				if(a[i][j]==y){
					fy=1;
					yt=t[i][j];
				}
			}
			if(fx&&fy){
				ans+=w[x]+w[y]+xt+yt;
				mi=min(mi,ans);
			}
		}
		cout<<mi<<endl;
	}
	
	return 0;
}
