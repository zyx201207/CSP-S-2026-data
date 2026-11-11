#include <bits/stdc++.h>
using namespace std;
long long n,c,num;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>a;
		for(int j=1;j<=c;j++)
		{
			s+=a;
		}
	}
	for(int i=0,j=s.size()-1;i*i<s.size();i++,j--)
	{
		if(s[i]!=s[j])
		{
			num++;
		}
	}
	cout<<num<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
