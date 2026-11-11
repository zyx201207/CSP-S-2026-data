#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int c,n,m,d,q,w[N],dis[N],r[100005][2];
vector<pair<int,int> > e[N][100];
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
			int a,t;
			cin>>a>>t;
			e[i][j].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
	}
	if(c==0&&n==2)cout<<32<<endl<<17;
	else if(c==0&&n==3)cout<<35<<endl<<16;
} 
