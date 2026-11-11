#include <bits/stdc++.h>
using namespace std;
int a[1000010];
char c[1000010];
struct point {
	int pn,pid;
};
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long len=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long ans=0;
	point p1= {1,1},p2= {n,a[n]};
	long long p=0,q=0;
	while(q<=len/2-a[p]){
		q+=a[p++];
	}
	int pid=len/2-q;
	while(p1.pn<p2.pn) {
		if (a[p1.pn]-p1.pid>p2.pid) {
			int cmp=a[p2.pn];
			if(c[p1.pn]!=c[p2.pn])ans+=cmp;
			p2.pn--;
			p2.pid=a[p2.pn];
			p1.pid+=cmp;
		} else if(a[p1.pn]-p1.pid+1==p2.pid) {
			if(c[p1.pn]!=c[p2.pn])ans+=a[p2.pn];
			p1.pn++;
			p2.pn--;
			p2.pid=a[p2.pn];
			p1.pid=1;
		} else {
			int cmp=a[p1.pn];
			if(c[p1.pn]!=c[p2.pn])ans+=cmp;
			p1.pn++;
			p1.pid=1;
			p2.pid-=cmp;
		}
	}
	cout<<ans;
	return 0;
}