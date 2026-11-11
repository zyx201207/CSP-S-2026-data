#include<bits/stdc++.h>
using namespace std;
long long n,a,q=0;
char v;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>v;
		for(int j=1;j<=a;j++)
		  s+=v;
	}
	for(long long i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-1-i]) q++;
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
