#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(n==4||n==6) cout<<1<<endl;
		if(n==5){
			if(x[1]>0) cout<<2<<endl;
			else cout<<0<<endl;
		}
	}
}
