#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],n,d[200005];
char c[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	cin>>d[1]>>c[1];
	b[1]=d[1],a[1]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>d[i]>>c[i];
		a[i]=b[i-1]+1;
		b[i]=b[i-1]+d[i];
	} 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=d[i];j++)
			s+=c[i];
	int sum=s.size();
	int m=sum/2;
	while(m--)
		if(s[sum/2-m-1]!=s[sum-1-m]) cnt++;
	cout<<cnt;
	return 0;
}
 

