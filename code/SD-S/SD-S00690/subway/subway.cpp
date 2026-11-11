#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int t[500005];
int f[505][505];
vector<int> line[505];
vector<int> wl[505],ws[505];
vector<int> station[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		wl[i].push_back(y);
		ws[x].push_back(y)
		line[i].push_back(x);
		station[x].push_back(i);
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int ka=0;ka<line[i].size();ka++){
				for(int kb=0;kb<line[j].size();kb++){
					if(line[i][ka]==line[j][kb]){
						f[i][j]=ws[line[i][ka]][i-1]+ws[line[j][kb]][j-1];
					}
				}
			}
		}
	}
	int l,r;
	while(q--){
		cin>>l>>r;
		int ans=0x3f3f3f3f;
		for(int i=0;i<=station[l].size();i++){
			for(int j=0;j<=station[r].size();j++){
				ans=min(ans,f[i][j])
			}
		}
		cout<<t[l]+t[r]+ans<<"\n";
	}
	return 0;
}
