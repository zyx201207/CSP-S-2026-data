#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans1=0,ans2=0;
		bool p=0;
		for(int i=1;i<=n-1;i++){
			if(a[i+1]-a[i]>d){
				ans+=ans1*ans2;
				ans1=0;ans2=0;
				p=0;
			}else
			if(a[i+2]-a[i]>d){
				if(p==0){
					ans1++;
				}else{
					ans2++;
				}
			}else{
				if(p==0){
					ans1++;
					ans2=0;
					p=1;
				}else{
					ans2++;
					ans+=ans1*ans2;
					p=1;
					ans1=ans2-1;
					ans2=0;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
