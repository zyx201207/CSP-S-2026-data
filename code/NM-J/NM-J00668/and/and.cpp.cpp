#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m,a[2005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mx=0,nx=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n&&j!=i;j++){
			nx=a[i]&a[j];
			mx=max(nx,mx);
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
