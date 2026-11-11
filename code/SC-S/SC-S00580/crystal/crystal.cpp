#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
long long n,m,mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	//cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long u=0,ll=i,rr=i;
		while(u<=m){
			if(ll-1>=1&&a[i]==a[ll-1]){
				ll--;
				continue;
			}if(rr+1<=n&&a[i]==a[rr+1]){
				rr++;
				continue;
			}
			long long u1=abs(a[i]-a[ll-1]),u2=abs(a[rr+1]-a[i]);
			if(ll-1>=1&&rr+1<=n&&u1<u2&&u+u1<=m){
				ll--;
				u+=u1;
			}
			else if(rr+1<=n&&a[rr+1]-a[i]+u<=m){
				rr++;
				u+=u2;
			}else{
				u=m+1;
			}
		}
		//cout<<ll<<" "<<rr<<'\n';
		mx=max(mx,rr-ll+1);
	}
	printf("%lld",mx);
	//cout<<mx;
	return 0;
} 