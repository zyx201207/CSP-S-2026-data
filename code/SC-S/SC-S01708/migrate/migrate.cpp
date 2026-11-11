#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,anse=0;
	cin>>c>>t;
	for(int ii=0;ii<t;ii++){
		int n,d,p=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n-2;i++)if(a[i+1]-a[i]!=a[i+2]-a[i+1])p=0;
		if(p==1){
			int D=a[2]-a[1];
			anse=n-2*d+1;
		}
		else{
		    anse=0;
		}
		cout<<anse<<endl;
	}
	return 0;
}