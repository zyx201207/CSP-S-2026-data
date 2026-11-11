#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int>a[505];
//int a[505][500005];
vector<int>t[505];
int tong[500005]={0};
vector<int>g;
//int t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(;q-->0;){
		int x,y;
		cin>>x>>y;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				tong[a[i][j]]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(tong[i]>1) g.push_back(i);
		}
		int ans=0;
		for(int i=1;i<=g.size();i++){
			int x,y;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[j][k]==g[i]){
						x=j,y=k;
						break;
					}
				}
			}
			ans+=(2*w[g[i]]+2*t[x][y]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
