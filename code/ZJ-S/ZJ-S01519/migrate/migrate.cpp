#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;cin>>c>>T;
	while(T--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int m=a[2]-a[1];
		int ans=0;
		int lt=1,rt=1;
		while(lt<=rt&&rt<=n){
			if(a[rt]-a[lt]<=d){
				rt++;
				continue;
			}
			if(a[rt]-a[lt]>=2*d){
				lt++;
				continue;
			}
			int mid=(lt+rt)/2;
			if(a[mid]-a[lt]<=d&&a[rt]-a[mid]<=d&&a[rt]-a[mid-1]>d){
				ans++;
			}
			lt++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

/**
8pts?
**/
