#include <bits/stdc++.h>
using namespace std;

int c[30]={0};
struct A {
	int s;
	int jz;
};

bool cmp (A z,A y) {
	return z.s>y.s;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdin);
	
	int n;
	int m;
	cin>>n;
	cin>>m;
	
	A a[200000];
	for (int i=0; i<n; i++) {
		cin>>a[i].s;
		int t=1;
		a[i].jz=0;
		while (t<=a[i].s) {
			t*=2;
			a[i].jz++;
		}
		a[i].jz--;
	}
	
	sort(a,a+n,cmp);
	
	int ans=a[0].s;
	for (int i=1; i<m; i++) {
		ans=ans&a[i].s;
		c[a[i].jz]++;
		if (c[a[i].jz]==m) {
			cout<<ans;
			break;
		}
		if (a[i].jz!=a[i-1].jz) {
			for (int j=0; j<i-1; j++) {
				int cj=1;
				for (int k=0; k<a[j].jz; k++) {
					cj*=2;
				}
				a[j].s-=cj;
				int t=1;
				a[j].jz=0;
				while (t<=a[j].s) {
					t*=2;
					a[j].jz++;
				}
				a[j].jz--;
			}
			i=0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
