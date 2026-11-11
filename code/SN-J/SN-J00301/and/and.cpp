#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[300000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>> a[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int qwe=(a[i]);
			maxn=max((a[i] & a[j]),maxn);
		}
	}
	cout<<maxn;
}
