#include<bits/stdc++.h>
using namespace std;
long long int sum=0;
long long int cnt=0;
long long int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int k=1;k<=n;k++)
	{
		cin>>a[k]>>c[k];
		cnt+=a[k];
	}
	cnt/=2;
	long long int i=0,j=n,x=0;
	while(i<j && x<=cnt)
	{
		if(a[i]==0) i+=1;
		if(a[j]==0) j-=1;
		long long int y=0;
		y=min(a[i],a[j]);
		a[i]-=y;
		a[j]-=y;
		if(c[i]!=c[j]) sum+=y;
		x+=y;
	}
	cout<<sum;
	return 0;
}
