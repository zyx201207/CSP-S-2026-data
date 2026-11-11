#include<bits/stdc++.h>
#include<iostream>
const int maxn = 300000;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[maxn],b[maxn];
	for(int i=0; i<m; i++) {
		cin>>a[i];
	}
	for(int i=0; i<m; i++) {
		a[i] = (a[i]&a[i+1]);
	}
	a[m]=(a[m]&a[0]);
	for(int i=0;i<=m;i++){
		a[i]=max(a[i],a[i+1]);
	}
	cout<<max(a[1],a[2]);
	return 0;
}

