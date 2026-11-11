#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int n,a[N],cnt,ans;
string s1;
char s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s;
		for(int j=cnt+1;j<=cnt+a[i];j++)
		{
			s1[j]=s;
		}
		cnt+=a[i];
	}
	for(int i=1,j=cnt;i<=cnt/2;i++)
	{
		if(s1[i]!=s1[j])
		{
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}
