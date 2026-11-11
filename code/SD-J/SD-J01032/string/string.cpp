#include<bits/stdc++.h>
using namespace std;
long long n,sum,a,ans;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s[i]=c;
		sum+=a;
	}
	if(n<=1) 
	{
		cout<<"0";
		return 0;
	}
	int l=sum/2;
	for(int i=1,j=sum;i<l,j>l;i++,j--)
	{
		if(s[i]!=s[j]) 
			ans++;
	}
	cout<<ans<<"\n";
	return 0;	
}
