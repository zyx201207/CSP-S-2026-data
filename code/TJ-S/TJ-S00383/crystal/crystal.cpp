#include<iostream>
#include<algorithm>
using namespace std;
//T1
//crystal
//AC!!!!!!
//pts=100
#define int long long
int n,m,ans=0;
int a[500005],sum[500005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("test.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int now=0,l=1,r=1;
	for(r=1;r<=n;r++){
		now=(r-l+1)*a[r]-(sum[r]-sum[l-1]);
//		cout<<now<<' '<<l<<' '<<r<<endl;
		for(;now>m&&r<=n;l++){
			now=(r-l+1)*a[r]-(sum[r]-sum[l-1]);
//			cout<<"-------- "<<now<<' '<<l<<' '<<r<<endl;
			if(now<=m){
				break;
			}
		}
//		cout<<"---- "<<now<<' '<<l<<' '<<r<<endl;
		if(r<=n){
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
} 
/*
Oct31==Dec25?
3
4
3485
315275

*/
