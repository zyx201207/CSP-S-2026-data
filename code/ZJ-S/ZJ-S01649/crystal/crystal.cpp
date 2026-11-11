#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=5e5+5;
int ans=1,last1=1,flag=0;
long long n,m,a[N],last=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;++i){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
			break;
		}
	}
	if(!flag&&n>=3){
		long long gc=a[2]-a[1];
		long long l=1,r=sqrt(2*m);
		while(l+1<r){
			long long mid=l+(r-l)/2;
			int tot=0;
			if(mid%2==0){
				tot=((mid/2)*(mid+1));
			}
			else tot=((mid+1)/2*mid);
			if(tot*gc>m) r=mid;
			else l=mid;
		}
		cout<<min(r,n);
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(i==1) continue;
		last+=(a[i]-a[i-1])*(i-last1);
		if(last<=m){
			ans=max(ans,i-last1+1);
		}
		else{
			for(int j=last1;j<i;++j){
				last1=j+1;
				last-=(a[i]-a[j]);
				if(last<=m)break;
			}
			ans=max(ans,i-last1+1);
		}
	}
	cout<<ans;
	return 0;
}
