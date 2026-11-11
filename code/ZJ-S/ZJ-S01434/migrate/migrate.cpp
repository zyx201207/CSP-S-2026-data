#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T,n,d,a[2000006],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d<=j&&a[j]-d>=i&&a[i]+d>=a[j]-d&&(lower_bound(a+1,a+1+n,a[j]-d)-a)+1==(upper_bound(a+1,a+1+n,a[i]+d)-a-1)){
					ans++;
				}
			}
		}cout<<ans<<'\n';
	}
}

