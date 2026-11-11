#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,d,q,w[N],huan[520][520],f[520][520][520];
vector<pair<int,int> > t[N];
signed main()
{
	int c;
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int stop,time;
			cin>>stop>>time;
			t[stop].push_back({i,time});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)huan[i][j]=1e5;
			else huan[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i].size()>1){
			for(int j=0;j<t[i].size();j++){
				for(int k=j+1;k<t[i].size();k++){
					int xxx=t[i][j].second+t[i][k].second;
					int stp1=t[i][j].first,stp2=t[i][k].first;
					huan[stp1][stp2]=min(huan[stp1][stp2],xxx);
					huan[stp2][stp1]=huan[stp1][stp2];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j][0]=huan[i][j];
			else f[i][j][0]=0;
			for(int k=1;k<=n;k++)f[i][j][k]=1e15;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)f[i][j][k]=min(f[i][k][k-1]+f[k][j][k-1],f[i][j][k-1]);
				else f[i][j][k]=f[i][j][k-1];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int qidi,zhong;
		cin>>qidi>>zhong;
		int ans=1e15;
		for(auto qi:t[qidi]){
			for(auto zh:t[zhong]){
				ans=min(ans,qi.second+zh.second+f[qi.first][zh.first][n]);
			}
		}
		cout<<ans+w[qidi]+w[zhong]<<"\n";
	}
	return 0;
}


