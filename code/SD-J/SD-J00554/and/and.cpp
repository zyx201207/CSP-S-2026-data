#include<bits/stdc++.h>
using namespace std;

int a[100006];
int b[10000005];
bool cmp(long x,long y)
{
	return x>y;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int m;int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	return 0;
}
