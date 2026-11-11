#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500500],b[500500];
bool f=true; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=abs(a[i]-a[i-1]);
	}
	for(long long i=2;i<=n-1;i++){
		//cout<<b[i]<<' '<<b[i+1];
		if(b[i]!=b[i+1]){
			f=false;
		}
	}
	if(f==true){
		long long times=m/b[2];
		//cout<<times<<endl;
		while(ans<n){
			times-=ans;
			if(times<0){
				break;
			}
			//cout<<times<<' '<<ans<<endl; 
			ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
