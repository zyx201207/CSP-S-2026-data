#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long list[n],cha1=0,keep=1;
	for (long long i=0;i<n;i++) {
		cin>>list[i];
		if (i==1) {
			cha1=list[i]-list[i-1];
		}
		if (i>1 && (cha1!=(list[i]-list[i-1]))) {
			keep=0;
		}
	}
	if (keep) {
		for (long long i=1;i<n;i++) {
			if ((i+1)*i/2*cha1>m) {
				cout<<i<<endl;
				return 0;
			}
		}
	}
	sort(list,list+n);
	int cha[n];
	for (int i=1;i<n;i++) {
		cha[i]=list[i]-list[i-1];
	}
	for (int i=1;i<n;i++) {
		int min1=INT_MAX;
		for (int j=i;j<n;j++) {
			int cnt=0;
			for (int k=j,l=1;l<=i;l++,k--) {
				cnt+=cha[k]*(i-l+1);
			}
			min1=min(min1,cnt);
		}
		if (min1>m) {
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
