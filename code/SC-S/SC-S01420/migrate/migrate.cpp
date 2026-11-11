#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				long long cnt=0,cnt1=0;
				bool f=0;
				for(int k=j;k<=i;k++){
					if(k!=j&&x[k]-x[k-1]>d){
						f=1;
					}
					if(x[k]-x[j]<=d){
						cnt=k;
					}
					if(x[k]-x[j]<=2*d){
						cnt1=k;
					}
				}
				if(cnt==cnt1||f==1){
					continue;
				}
				long long cnt2=0;
				for(int k=cnt-1;k>=j;k--){
					if(x[cnt1]-x[k]<=d){
						cnt2++;
					}
				}
//				cout<<i<<" "<<j<<" "<<cnt2<<endl;
				if(cnt2==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}