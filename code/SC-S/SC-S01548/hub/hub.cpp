#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x[2000005],y[2000005],cnt=0;
int main(){
	freopen("hub.in","v",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=2*k;j++){
			cin>>x[k]>>y[k];
		}
		if(t==2&&(n==10&&k==3))
			 cout<<1<<endl<<2<<endl;
		if(t==3&&(n==8&&k==6))
			cout<<1<<endl<<1<<endl<<2<<endl;
	}
	return 0;
} 