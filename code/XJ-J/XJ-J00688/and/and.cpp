#include<bits/stdc++.h>
using namespace std;
long long int a[1000005],n,b,i,j,m,flag,s,p,q=-1,w,maxn=-1,c;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
	b=a[i-1]&a[i];
	
	if(b>maxn)
	maxn=b;
}


	cout<<maxn;
	return 0;
}//4 2 3 15 12 12
//5 3 31 3 1 15 7
