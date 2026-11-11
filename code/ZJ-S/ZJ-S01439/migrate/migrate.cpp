#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n;
long long d,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d and a[i+3]-a[i+1]<=d and a[i+3]-a[i]>d){
				ans++;
				for(int j=i+1;j<=n-3;j++){
					if(a[j+3]-a[j+2]<=d and !(a[j+2]-a[j]<=d and a[j+3]-a[j+1]<=d and a[j+3]-a[j]>d)) ans++;
					else break;
				}
				for(int j=i-1;j>=1;j--){
					if(a[j+1]-a[j]<=d and !(a[j+2]-a[j]<=d and a[j+3]-a[j+1]<=d and a[j+3]-a[j]>d)) ans++;
					else break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
