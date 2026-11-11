#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+2);
	bool kk_a=true;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) kk_a=false;
	}
	sort(a.begin()+1,a.end()-1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	if(kk_a) {
		if(m==0) {
			cout<<1<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		long long l=1,r=n,p,sum=-1;
		while(l<=r) {
			long long mid=(l+r)/2;
			if(mid%2==0) p=mid/2*(mid-1);
			else p=(mid-1)/2*mid;
			if(p<=m) {
				sum=mid;
				l=mid+1;
			} else {
				r=mid-1;
			}
		}
		cout<<min(sum,n)<<endl;
	} else {
		long long p=0,sum=-1,ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i; j>=1; j--) {
				if(p+a[i]-a[j]<=m) {
					p+=a[i]-a[j];
					ans++;
				} else break;
			}
			sum=max(ans,sum);
			ans=0;
			p=0;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
