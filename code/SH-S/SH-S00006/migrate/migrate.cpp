#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		long long x[2],cha,zc;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i%2];
		}
		cha=abs(x[1]-x[0]);
		zc=n;
		if(c>=11&&c<=12||c==0){
			long long uf=d/cha;
			uf=uf*2;
			if(uf==0||d==cha) cout<<0<<endl;
			else if(zc-uf+1>0) cout<<zc-uf+1<<endl;
			else cout<<0<<endl;
		}
		else cout<<cha<<endl;
	}
	return 0;
}
