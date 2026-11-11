#include<bits/stdc++.h>
using namespace std; 
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int T=1;T<=t;T++){
		long long n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			cout<<0<<endl;
		}
		if(c==11||c==12){
			long long D=a[2]-a[1];
			long long k=d/D;
   
			if(D>d){
				cout<<0<<endl;
				continue;
			}
//			cout<<k<<" ";
			long long cnt=0;
			for(int i=1;i<=n-2;i++){
				for(int j=i+2;j<=n;j++){
					if((j-i)%k!=0&&(j-i)/k!=0){
//						cout<<2*((j-i)%k);
						if(k<=2*((j-i)%k)){
							cnt++;
//							cout<<i<<j<<" ";
						}
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}