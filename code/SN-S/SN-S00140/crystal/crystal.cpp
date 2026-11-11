#include<bits/stdc++.h>
using namespace std;
int a[500025],b,c,ans,sum,cnt,n,m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	sum=m;
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0; i<n; i++) {
		if(!cnt) {
			cnt++;
			ans=max(ans,cnt);
		} else {
			if(sum>=(a[i]-a[i-1])*cnt) {
				sum-=(a[i]-a[i-1])*cnt;
				cnt++;
				ans=max(ans,cnt);
			} else {
				while(sum<(a[i]-a[i-1])*cnt) {
					sum=sum+a[i-1]-a[i-cnt];
					cnt--;
				}
				sum-=(a[i]-a[i-1])*cnt;
				cnt++;
				ans=max(ans,cnt);
			}
		}
	}
	printf("%d",ans);
}
