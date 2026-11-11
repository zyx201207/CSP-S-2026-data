#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	int m,n,i;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sort(a+1,a+1+i,greater<int>());
	}
	cout<<a[n];
	return 0;
}
