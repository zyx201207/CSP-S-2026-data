#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
struct node{
	int a,t;
}z[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=2*k;i++) cin>>z[i].a>>z[i].t;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	return 0;
} 
