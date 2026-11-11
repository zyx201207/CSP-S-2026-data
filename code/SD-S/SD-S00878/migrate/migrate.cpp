#include<bits/stdc++.h> 
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],sum; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12||c==0){
			long long f=max(a[2]-a[1],a[1]-a[2]);
			if(d<2*f){
				cout<<0<<endl;
			}else{
				cout<<max(0ll,n-(d/f)*2+1)<<endl;
			}
		}else if(c==13||c==14){
			cout<<((n-1)*(n-2))/2;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					long long j2=j+1;
					for(int k=j+1;k<=n;k++){
						if(a[k]-a[i]<=2*d&&a[k]-a[j]<=d&&a[j]-a[i]<=d&&a[k]-a[j2]<=d&&a[j2]-a[i]<=d){
							sum++;
						}
					}
				}
			}
			cout<<sum;
		} 
	}
	return 0;
}
