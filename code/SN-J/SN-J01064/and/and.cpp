#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x,a[100005],d=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[3];
	return 0;
}
