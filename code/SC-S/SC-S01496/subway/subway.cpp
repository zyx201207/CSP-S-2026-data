#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,a[500005];
struct hh{
	int di;
	int l;
};
vector <hh>line[500005];
vector <hh>pic[500005];
int spfa[505][505];
int main(){
	int flag=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int gs;
		cin>>gs;
		if(gs!=2){
			flag=1;
		}
		for(int j=1;j<=gs;j++){
			int e,t;
			cin>>e>>t;
			line[j].push_back({e,t});
		}
	}
	if(flag==1){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<a[x]+a[y]<<endl;
		}
			return 0;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			spfa[i][j]=INT_MAX;
	for(int i=1;i<=n;i++){
		spfa[line[i][0].l][line[i][1].l]=line[i][1].di+line[i][0].di;
		spfa[line[i][1].l][line[i][0].l]=line[i][1].di+line[i][0].di;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(spfa[i][k]!=INT_MAX&&spfa[k][j]!=INT_MAX){
					spfa[i][j]=min(spfa[i][j],spfa[i][k]+spfa[k][j]);
					spfa[j][i]=spfa[i][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<spfa[x][y]+a[x]+a[y];
	}
	return 0;
}