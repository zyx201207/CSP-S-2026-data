#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<a[n];
		return 0;
	}
	sort(a,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
