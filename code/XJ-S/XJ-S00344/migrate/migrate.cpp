#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long ans;
	long long n,d;
	for(int o=0;o<t;o++){
		cin>>n>>d;
		ans=0;
		long long a[n];
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}sort(a,a+n);
		for(long long i=0;i<n;i++){
			if(a[i+3]-a[i]>d && a[i+1]-a[i]<=d && a[i+2]-a[i]<=d && a[i+3]-a[i+1]<=d && a[i+3]-a[i+2]<=d){
				ans++;
			}
		}cout<<ans<<endl;
	}
	
	return 0;
}
