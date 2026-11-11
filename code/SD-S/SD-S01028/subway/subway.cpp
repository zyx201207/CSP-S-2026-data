#include<bits/stdc++.h>
using namespace std;

long long c1,n,m,d,q;
long long w[500500];
vector<long long> c[550];
vector<long long> t[550];
vector<long long> e[550];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>c[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i].size();j++){
			e[c[i][j]][e[c[i][j]].size()+1]=c[i][j+1];
			e[c[i][j+1]][e[c[i][j+1]].size()+1]=c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i].size();j++){
			cout<<i<<":"<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
