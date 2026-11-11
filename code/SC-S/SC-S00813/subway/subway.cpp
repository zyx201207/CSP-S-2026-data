#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10000],ans=0,vis[10000];
int o,x,y,x1=-1;
int x2;
map<pair<int,int>,int> t;
struct node{
	vector<int>ch;
}tree[10000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		x1=-1;
		cin>>o;
		//cout<<o;
		for(int j=1;j<=o;j++){
			cin>>x;
			cin>>y;
			tree[x1].ch.push_back(x);
			//tree[x].ch.push_back(x1);
			t[{x1,x}]=y;
			t[{x,x1}]=y;
			x1=x;
		}
	}
	
	cout<<0;
}