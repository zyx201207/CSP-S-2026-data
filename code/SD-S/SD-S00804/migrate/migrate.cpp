#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000005];
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			a[i]=0;
		}
		/*for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(x[i]+d*2>=x[j]){
					a[j]+=2;
				}
			}
		}*/
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					a[j]++;
				}
				else{
					break; 
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i]<<' ';
			if(a[i]==2){
				ans++;
			}
		}
		cout<<ans-1<<endl;
	}
}
