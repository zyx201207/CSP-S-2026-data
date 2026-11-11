#include<bits/stdc++.h>
using namespace std;
#define N 600005
#define int long long
int n,m;
int a[N];
int qzh[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	qzh[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		qzh[i]=qzh[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1;
		int r=i;
		while(l<r){
			int mid=(l+r)/2;
			int len=i-mid+1;
			int sum=qzh[i]-qzh[mid-1];
			if(len*a[i]-sum<=m){
				r=mid;
//				cout<<mid<<'\n';
			}else{
//				cout<<l<<" "<<r<<" "<<mid<<" "<<len<<" "<<sum<<" "<<len*a[i]-sum<<'\n';
				l=mid+1;
			}
		}
		int na=i-l+1;
//		cout<<i<<" "<<na<<'\n';
		ans=max(ans,na);
//		cout<<l<<" "<<i<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
