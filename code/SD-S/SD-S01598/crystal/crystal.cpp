#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b;
bool flag=true;
long long s[500100],sum[500100],cnt,ans,answ;
int main() {
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++) {
		if(i==2) cnt=a[i]-a[i-1];
		if(a[i]-a[i-1]!=cnt&&i>=2) flag=false;
	}
	if(flag) {
		if(cnt==0)cout<<n;
		else {
		b=m/cnt;	
			int l=1;
			for(int i=n-1; i>=1; i--) {
				if(b-l>=0) {
					ans++;
					b-=l;
				} else break;
				l++;
			}
			cout<<ans+1;
		}
	} else {
		for(int i=2; i<=n; i++) {
			cnt=m;
			for(int j=1; j<i; j++) {
				sum[j]=a[i]-a[j];
			}
			for(int k=i-1; k>=1; k--) {
				if(cnt-sum[k]>=0) {
					cnt-=sum[k];
					ans++;
				} else break;
			}
			answ=max(ans,answ);
			ans=0;
		}
		cout<<answ+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
