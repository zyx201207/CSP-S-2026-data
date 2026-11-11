#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;int a[n],b[n*n]={0},step=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b[step]=(a[i] & a[j]);
			step++;
		}
	}for(int i=2;i<m;i++){
	for(int j=i;j<n;j++){
		b[j-i]=(b[j-i]&a[j]);
	}
}
	sort(b,b+n*n,greater<int>());
	cout<<b[0];
	return 0;
}
