#include<bits/stdc++.h>
using namespace std;
//const int N=500005;
//vector<int>g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	if(c==0){
		int n,m,d,q;
		cin>>n>>m>>d>>q;
		vector<int>w(n+1);
		long long sum=0;
		for(int i=1;i<=m;i++){
			cin>>w[i];
			sum+=w[i];
		}
		vector<int>k(n+1);
		for(int i=1;i<=n;i++){
			cin>>k[i];
			vector<vector<int> >a(k[i]+1,vector<int>(k[i]+1));
			vector<vector<int> >t(k[i]+1,vector<int>(k[i]+1));
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		vector<int>x(q+1),y(q+1);
		for(int i=1;i<=q;i++){
			cin>>x[i]>>y[i];
		}
		cout<<sum;
	} 
	return 0;
}
