#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,a,b=0,x=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
			b++;	
		} 
	}
	for(int i=0;i<b/2;i++)
	{
		if(s[i]!=s[b-i-1])
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}



