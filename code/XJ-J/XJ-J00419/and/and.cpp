#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a-1,a+n);
	cout<<a[n-m];
	return 0;
}
