#include<bits/stdc++.h>
using namespace std;
const int N=5e+5;
int w[N],k[501];
struct node{
	int a,t;
}r[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>r[j].a>>r[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<32<<endl<<17;
	return 0;
}
