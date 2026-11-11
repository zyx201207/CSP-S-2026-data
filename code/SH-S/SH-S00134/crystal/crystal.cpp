#include <bits/stdc++.h>
using namespace std;
int a[500004],cha[500003];
int main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,min_cha=0,ans=0;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	while (m > 0) {
		for (int i=0;i<n;i++) {
			if (i >= 1) {
				cha[i-1]=a[i]-a[i-1];
				if (i == 1) {min_cha = cha[0];}
				if (i >= 2) {min_cha = min(cha[i-1], min_cha);}
			}
		}
		for (int j=1;j<n;j++) {
			if (a[j]-a[j-1] == min_cha) {
				a[j-1] += min_cha;
				m-=min_cha;
			}
		}
	}
	int x=1,y=0,q=a[0];
	for (int p=1;p<n;p++) {
		if (a[p] == q) {
			x += 1;
		}
		else {
			q = a[p+1];
			if (y != 0) {
				x = max(x, y);
				ans = max(x, ans);
				x = 0;
				y = 0;
			}
			else {
				y = x;
				x = 1;
			}
		}
	}
	ans = max(x, y);
	printf("%d",ans);
	return 0;
}
