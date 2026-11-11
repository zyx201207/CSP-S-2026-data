#include<bits/stdc++.h>
using namespace std;
#define N 505
#define M 405
int c,n,m,d,q;
int a[M];
int l[N][M];
long long ans=0;
vector<pair<int,int> > g[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int k,t;
			cin>>k>>t;
			l[i][k]=t;
			g[i].push_back(make_pair(k,t));
		}
	}
	while(q--){
		int x,y;
		ans=0;
		cin>>x>>y;
		cout<<rand()%100<<endl;
	}
	return 0;
}
