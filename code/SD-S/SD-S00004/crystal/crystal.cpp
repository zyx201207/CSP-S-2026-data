#include<bits/stdc++.h>
using namespace std;
const int N=500007;
long long n,m;
long long a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=m;
	long long pop=1;
	long long ans=0;
	int flag=0;
	//特殊测试点xA
	int xA=0;
	for (int i=1; i<=n; i++) {
		if (a[i]!=i) {
			xA=1;
		}
	}
	if (xA==0) {
		pop=0;
		for (int i=1; i<=n; i++) {
			if (sum<0) {
				break;
			}
			sum=sum-i;
			pop=pop+1;
		}
		cout<<pop<<endl;
		return 0;
	}
	//特殊测试点xB
	int xB=0;
	int qw=a[2]-a[1];
	for (int i=2; i<=n; i++) {
		if (a[i]-a[i-1]!=qw) {
			xB=1;
		}
	}
	if (xB==0) {
		pop=0;
		for (int i=1; i<=n; i++) {
			if (sum<0) {
				break;
			}
			sum=sum-qw;
			qw=qw+qw;
			pop=pop+1;
		}
		cout<<pop<<endl;
		return 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=i; j>=1; j--) {
			if (flag==0) {
				if (sum-(a[i]-a[j])>0) {
					pop=pop+1;
					sum=sum-(a[i]-a[j]);
				} else {
					flag=1;
				}
			}
		}
		ans=max(pop,ans);
		flag=0;
		sum=m;
		pop=1;
	}
	cout<<ans<<endl;
	return 0;
}
/*Oct31==Dec25?*/
//O(n^2)
