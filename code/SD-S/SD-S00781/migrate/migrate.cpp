#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d,ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		ans=0;
		long long n,d;
		cin>>n>>d;
		long long a[n];
		for(long long i=0;i<n;i++) cin>>a[i];
		for(long long i=0;i<n-3;i++){
			if(a[i+3]-a[i]>d&&a[i+3]-a[i]<d*2){
				if(a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d)
				 	ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
