#include <bits/stdc++.h>
using namespace std;
struct node {
	long long num;
	char str;
} a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].str;
	}
	long long l=1,r=n,ans=0;
	while(l<=r) {
		if(a[l].str!=a[r].str) {
			if(a[l].num>a[r].num) {
				ans+=a[r].num;
				a[l].num-=a[r].num;
				r--;
			} else if(a[l].num==a[r].num) {
				ans+=a[r].num;
				a[l].num=a[r].num=0;
				l++,r--;
			} else {
				ans+=a[l].num;
				a[r].num-=a[l].num;
				l++;
			}
		} else {
			if(a[l].num>a[r].num) {
				a[l].num-=a[r].num;
				r--;
			} else if(a[l].num==a[r].num) {
				a[l].num=a[r].num=0;
				l++,r--;
			} else {
				a[r].num-=a[l].num;
				l++;
			}
		}
	}
	cout <<ans;
	return 0;
}
