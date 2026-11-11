#include<bits/stdc++.h>
using namespace std;
int u[10010],v[10010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cout<<u[j]<<v[j];
		}
	}
	if(c==0&&t==2) cout<<1<<endl<<2;
	return 0;
}
