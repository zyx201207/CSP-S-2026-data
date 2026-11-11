#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q;
int wk[500005],be[500005],num[500005];
int t[25][500005];
vector<int> line[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wk[i];
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			int x,y;
			cin>>x>>y;
			line[i].push_back(x);
			be[x]=i;
			t[i][x]=y;
		}
	}
	while(q--){
		int tot=0;
		int x,y;
		cin>>x>>y;
		tot+=(wk[x]+wk[y]);
		if(be[x]==be[y]){
			tot+=t[be[x]][x];
			tot+=t[be[y]][y];
		}
		cout<<tot<<'\n';
	}
	return 0;
}
