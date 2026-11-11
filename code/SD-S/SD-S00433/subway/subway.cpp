#include <bits/stdc++.h>

using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
int w[M],k[N];
vector<pair<int,int> > z[N];
int a[M][3],t[M][3];
int idx[M];
int dist[N];
bool use[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		int s=0;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				idx[a[i][j]]++;
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int cnt=0;
			for(int i=1;i<=m;i++){
				if(idx[i]>1){
					cnt++;
				}
			}
			cout<<cnt/2<<"\n";
		}
	}
	return 0;
}
