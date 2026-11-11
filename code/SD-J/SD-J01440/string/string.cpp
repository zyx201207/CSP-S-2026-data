#include <iostream>
using namespace std;
long long ans,b,man; 
string s;
char a;
int main()
{
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>b>>a;
		string m(b,a);
		s+=m;
		man+=b;
		
	}
	for(long long i=0;i<=man/2;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
