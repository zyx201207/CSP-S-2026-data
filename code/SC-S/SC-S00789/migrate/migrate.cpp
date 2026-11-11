#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[1000005],y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++)cin>>a[j];
		y=d/(a[2]-a[1]);
		if(y==0){
			cout<<"0\n";
			continue;
		}
		y*=2;
		cout<<n-y+1<<endl;
	}
	return 0;
}