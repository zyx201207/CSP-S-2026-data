#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],c[N],p[N];
int main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			b[a[j]]++;
			if(b[a[j]]>1) {
				for(int k=c[a[j]]; k<=j; k++) {
					b[a[k]]--;
				}
			}
			c[a[j]]=j;
		}
		for(int j=1; j<=n; j++) {
			if(b[a[j]]!=0) {
				p[j]++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(p[i]!=0) {
			cout<<p[i]<<endl;
		}
	}
	return 0;
}

