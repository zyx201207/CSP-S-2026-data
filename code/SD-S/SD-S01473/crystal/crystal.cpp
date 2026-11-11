#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
LL n,m;
LL a[N];
//int b[N],sum[N];
LL ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	LL x=a[2]-a[1],f=1;
	for(int i=3;i<=n;++i){
		if(a[i]-a[i-1]!=x){
			f=0;
			break;
		}
	}
	if(f==1){
		ans=sqrt(2*m);
		cout<<ans<<endl;
		return 0;
	}
//	for(int i=1;i<=n/2;++i){
//		b[i]=a[i/2]-a[i];
//		sum[i]=sum[i-1]+b[i];
//	}
	for(LL i=1;i<=n;++i){
		LL sum=0;
		for(LL j=1;j<=i;++j){
			sum+=a[i]-a[j];
		}
		if(sum<=m){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
} 
