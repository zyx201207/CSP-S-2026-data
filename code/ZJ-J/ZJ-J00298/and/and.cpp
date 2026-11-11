#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num=max(a[i],num);
	}
	cout<<num;
	return 0;
}