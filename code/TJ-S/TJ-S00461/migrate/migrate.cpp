#include<bits/stdc++.h>
using namespace std;
long long n,d,xly[20000005]={0},x[20000005],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			cin>>xly[i];
			x[i]=xly[i]-xly[i-1];
		}
		for(int i=2;i<n-1;i++){
			long long kd=x[i];
			if(x[i+1]+kd<=d&&x[i+2]+x[i+1]<=d&&i+2<=n&&x[i+2]+x[i+1]+kd>d){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
