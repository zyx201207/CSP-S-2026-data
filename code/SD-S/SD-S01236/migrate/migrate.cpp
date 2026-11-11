#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T;
int n;
ll d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				if(abs(a[i]-a[j])<=d) cnt=1;
				for(int k=i+1;k<j;k++){
					if(j-i==1) continue;
					if(abs(a[k]-a[i])<=d&&abs(a[k]-a[j])<=d){
						cnt++;
					}
				} 
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}

