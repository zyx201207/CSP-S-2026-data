#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,n,m,d,q;
int w[510];
int a[510][510];
vector<int>v[510];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int v;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int f,t;
			cin>>f>>t;
			v=t;
			a[i][f]=t;
			a[f][i]=t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(abs(x-y)+1)*v+w[x]+w[y]<<'\n';
	}
}

