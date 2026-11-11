#include<bits/stdC++.h>
#define int long long
using namespace std;
string s="";
int n,l=0,tot=0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",n);
	while(n--)
	{
		int a;
		string str;
		scanf("%d",a);
		cin>>str;
		l+=a;
		while(a--)
			s+=str;
	}
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1]) tot++;
	}
	printf("%d",tot);
	return 0;
}
