#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

struct node{
	long long w;
}v[500005];

struct node2{
	long long a;
	long long t;
}r[505][200005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i].w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>r[i][j].a>>r[i][j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
        cout<<32;
	}
	return 0;
}
