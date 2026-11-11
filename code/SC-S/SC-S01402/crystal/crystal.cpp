#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,n,m,l,cnt,max=0,use;
	cin >> n >> m ;
	long long a[n+1]={},b[n+1]={};
	for(i=1;i<=n;i++)
		cin >> a[i] ;	
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
		b[i]=a[i]-a[i-1];
	for(i=1;i<=n;i++)
	{
		use=0;
		cnt=0;
		for(l=i;l>=1;l--)
		{
			if(use+use+b[l]<=m)
			{
				use+=use+b[l];
				cnt++;
			}
			else
				break;
		}
		if(cnt>=max)
			max=cnt;
	}
	cout << max+1 ; 
	fclose("crystal.in");
	fclose("crystal.out");
	return 0; 
}