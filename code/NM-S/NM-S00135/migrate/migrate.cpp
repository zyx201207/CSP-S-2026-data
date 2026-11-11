#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,x[N];
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d<=1){
			cout<<0<<endl;
			continue;
		}
		long long sum=0;
		for(int i=1;i<n;i++){
			if(abs(x[i+1]-x[i])>d)continue;
			int k=i;
			for(int j=i+1;j<=n;j++){
				if(abs(x[j+2]-x[k])<=d)break;
				if(abs(x[j]-x[i])==d)k=j;
				else if(abs(x[j+1]-x[k])<=d&&abs(x[j+2]-x[k+1])<=d&&j<=n-2){
					sum++;
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
