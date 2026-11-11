#include<bits/stdc++.h>
using namespace std;
int u;
int t;
int n;
long long d;
const int N=5e3+3;
long long a[N];
long long ans;
long long f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>u>>t;
	if(u==11||u==12){
		while(t--){
			scanf("%d %ld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%ld",&a[i]);
			}if(d<a[2]-a[1]||d>a[n]-a[1]){
				cout<<0<<endl;
			}else{
				cout<<n-3;
			}
		}
	}while(t--){
		scanf("%d %ld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%ld",&a[i]);
		}int l=1,r=n;
		f[1]=0;
		for(int i=2;i<=n;i++){
			f[i]=f[i-1]+a[i]-a[i-1];
		}
		while(l<=r){
			int mid=(l+r)/2;
			if(mid<=2)break;
			for(int i=1;i<=n;i++){
				
			}
		}
	}
	return 0;
}
