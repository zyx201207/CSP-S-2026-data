#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct str {
	int l;
	char c;
} a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i].l>>a[i].c;
	int l=n;
	for(int i=1; i<=n; i++) {
		if(i==l) break;
		while(a[i].l>0) {
			if(a[l].l<a[i].l) {
				if(a[l].c!=a[i].c) sum+=a[l].l,a[i].l-=a[l].l,l--;
				else a[i].l-=a[l].l,l--;
			} else {
				if(a[l].c!=a[i].c) sum+=a[i].l,a[l].l-=a[i].l,a[i].l=0;
				else a[l].l-=a[i].l,a[i].l=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
