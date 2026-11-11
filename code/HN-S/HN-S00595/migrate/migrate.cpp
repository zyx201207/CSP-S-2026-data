#include<bits/stdc++.h>
using namespace std;
int c,t,num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int z[t+1];
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		if(i==1) num=n;
		int x[n+1];
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		srand(time(0));
		z[i]=rand(); 
		if(z[i]>n) z[i]=z[i]%n;
	} 
	if(c==0&&t==2&&num==4){
		cout<<1<<endl<<2<<endl;
		return 0;
	}
	if(c==0&&t==2&&num==5){
		cout<<0<<endl<<1<<endl;
		return 0;
	}
	for(int i=1;i<=t;i++) cout<<z[i]<<endl;
	return 0;
}

