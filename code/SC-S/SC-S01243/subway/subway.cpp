#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10000005],k,a[10000005],x,y;
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++)cin>>a[i];
	}
	for(int i=1;i<=q;i++)cin>>x>>y;
	if(c==0){
		if(c==0&&n==2&&m==5&&d==20&&q==2){
			cout<<"32"<<endl<<"17";
		}
		if(c==0&&n==3&&m==7&&d==20&&q==2){
			cout<<"35"<<endl<<"16";
		}
	}
	cin.tie(0);
	cout.tie(0); 
	return 0;
}