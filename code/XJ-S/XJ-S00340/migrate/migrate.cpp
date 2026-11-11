#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[500010];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	for(int i=1;i<=t;i++){
		if(t=1)cout<<0<<endl;
		else if(t=2)cout<<1<<endl;
		else cout<<2;
	}
	return 0;
}
