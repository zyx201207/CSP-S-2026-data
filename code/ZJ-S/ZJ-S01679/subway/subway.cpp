#include<bits/stdc++.h>
using namespace std;
const long long N=1e2+5;
int c,n,m,d,q,w[N],x[N],y[N];
struct node{
	long long a,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	node at[N][N];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>at[i][j].a>>at[i][j].t;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<3*x[i]<<y[i]/2*3;
		cout<<"\n";
	}
	return 0;
}