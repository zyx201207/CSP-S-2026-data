#include<bits/stdc++.h> 
using namespace std;
int n,a,cishu,l;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		    s+=c;
	}
	l=s.size();
	for(int i=1;i<=l;i++)
	{
		if(s[i-1]!=s[l-i]) cishu++;
	}
	cout<<cishu/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
