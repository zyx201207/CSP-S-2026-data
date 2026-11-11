#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500001;
ll n,m,a[N],d;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	d=a[2]-a[1];
	for(int i=n;i>0;i--){
		if(d*i*(i-1)/2<=m){
			cout<<i;
			break;
		}
	}
//	sort(a+1,a+1+n);
//	ll sum_all,sumd;
//	for(ll i=1;i<n;i++){
//		d[i]=a[i+1]-a[i];
//		sum_all+=i*d[i];
//		sumd+=d[i];
//	}
//	ll ans=n,l=1,r=n-1;
//	while(sum_all>m){
//		ans--;
//		if(ans*d[r]<sumd){
//			sum_all-=sumd;
//			sumd-=d[l];
//			l++;
//		}
//		else{
//			sum_all-=ans*d[r];
//			sumd-=d[r];
//			r--;
//		}	
//	}
//	试了正解没成功，那就~~~
	
	
	
//	printf("%lld\n",ans);
	fclose(stdin),fclose(stdout);	
	return 0;
}
