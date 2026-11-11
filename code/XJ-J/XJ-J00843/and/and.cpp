#include <bits/stdc++.h>
using namespace std;
int a[2000000],m,n;
bool cmp(int a,int b){
	return a<b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[n/2];
	return 0;
}