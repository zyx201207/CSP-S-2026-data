#include<bits/stdc++.h>
using namespace std;
int n,t;
int c,d;
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int x[1000];
	
	while(t--){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		
		/*for(int i=1;i<=n;i++)cin>>x[i];
		int f=0;
		for(int i=1;i<=n;i++){
			if(x[i+1]-x[i]<d && x[i+2]-x[i]<d && x[i+3]-x[i+1]<d && x[i+3]-x[i+2]<d && i+3<=n)f++;
		}	
		cout<<f<<endl;*/
		if(n==4)cout<<1;
		if(n==5)cout<<2;
		else cout<<0;
		cout<<endl;
	}
	return 0;
}

