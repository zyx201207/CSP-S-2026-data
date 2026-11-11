#include<bits/stdc++.h>
using namespace std;
long long int n,a[500500],ch[500500],s[500500],s2[500500],da=0,m,k,j=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m>>k;
	n--;
	for(long long int i=1;i<=n;i++) {cin>>a[i];a[i]-=k;}
	sort(a+1,a+n+1);
	for(long long int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(long long int i=1;i<=n;i++)
	{
		while((j-i+1)*a[j]-(s[j]-s[i-1])<=m && j<=n) j++;
		j--;
		da=max(da,j-i+2);
		if(j==n) break;
	}
	cout<<da;
	return 0;
}
/*rp++!feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(feropen(*/
