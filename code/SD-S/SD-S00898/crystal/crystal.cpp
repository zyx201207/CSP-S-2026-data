#include<bits/stdc++.h>
using namespace std;
const int M=5e5;
long long n,m,a[M+5],suf[M+5],cnt[M+5],ans=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cnt[i]=1;
	}
	sort(a+1,a+n+1);
	int l=n+1,r=n+1;
	long long sum=0,c=0;
	while(r>1) {
		r--;
//		cout<<"r:"<<r<<endl;
//		cout<<"sum:"<<sum<<endl;
		if(l<=r)sum-=a[r];
		else l=r;
		if(r>1&&a[r]==a[r-1]) {
			cnt[r-1]=cnt[r]+1;
			continue;
		}
		long long c=r-l;
		while(true) {
//			cout<<"l:"<<l<<endl;
//			cout<<"sum:"<<sum<<endl;
			c=r-l;
			int pl=l-1,psum=sum+a[pl],pc=r-pl; 
			if(pl>0&&psum+m>=pc*a[r]) {
				l--;
				sum+=a[l];
			}else{
				break;
			}
		}
//		cout<<"cnt["<<r<<"]:"<<cnt[r]<<endl;
		ans=max(ans,c+cnt[r]);
//		cout<<"ans:"<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

