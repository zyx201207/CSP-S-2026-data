#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],he=0;
	char c[200005];
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	    for(int j=0;j<a[i];j++)
	        s=s+c[j];
	}
	for(int i=0;i<s.size();i++)
	    for(int j=s.size()-1;j>=0;j--)
	    {
	    	if(s[i]!=s[j]) he++;
		}
	cout<<he;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
