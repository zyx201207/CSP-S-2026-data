#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],f[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int sum=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			f[i]=f[i-1]+x[i]-x[i-1];
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(f[j]-f[i]>d) sum++;
			}
		}
		cout<<(n-1)*n/2-n-1-sum<<"\n";
	}
	return 0;
}
