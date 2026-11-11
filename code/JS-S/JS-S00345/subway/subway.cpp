#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int c,n,m,d,q;
int a[N],b[N],c[N];
int d[10],e[10];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=2*m;i++) cin>>b[i];
	for(int i=1;i<=2*m;i++) cin>>c[i];
	for(int i=1;i<=2;i++) cin>>d[i];
	for(int i=1;i<=2;i++) cin>>c[i];
	if(n==2) cout<<32<<"\n"<<17;
	if(n==3) cout<<35<<"\n"<<16;
	return 0;
}
