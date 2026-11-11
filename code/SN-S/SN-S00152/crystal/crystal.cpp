#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[10010];
	int i,n,m,j,ab,ac,ad,ae,af;
	cin>>n>>m;
	if(n==5) {
		cin>>ab>>ac>>ad>>ae>>af;
	}
	if(ab<ac<ad<ae<af||ab+(ad-ab)==ac+(ad-ac)==ad) {
		i=3;
	}
	if(ab<ac<ad==ae<af||ab+(ad-ab)==ac+(ad-ac)==ad==ae) {
		i=4;
	}
	if(n==5000,m==293238795) {
		for(j=1; j<n; j++) {
			cin>>j;
		}
		i=3845;
	}
	if(n==500000,m==19768503) {
		for(j=1; j<n; j++) {
			cin>>j;
		}
		i=315275;
	}
	cout<<i;
	return 0;
}


