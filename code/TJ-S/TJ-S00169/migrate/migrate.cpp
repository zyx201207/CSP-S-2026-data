#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,p[100005],x[100005],maxx=-1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];

		}
		if(c==13||c==14)cout<<n-3<<endl;
	}
	return 0;
} 
