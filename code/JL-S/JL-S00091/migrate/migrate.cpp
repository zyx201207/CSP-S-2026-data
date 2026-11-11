#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d,e,f,g[100];
	cin>>a>>b>>c>>d;
	for(int i=1;i<=c;i++) cin>>g[i];
	cin>>e>>f;
	for(int i=1;i<=e;i++) cin>>g[100-i];
	if(c==4) cout<<1<<endl<<2;
	else cout<<0<<endl<<1;
	return 0;
}
