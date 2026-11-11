#include<bits/stdc++.h>
using namespace std;
long long n,sum,b;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b>>a;
		for(int j=0;j<b;j++) s+=a;
	}
	for(int i=0,j=s.size()-1;(j-i)>=1;i++,j--)
	{
		if(s[i]!=s[j]) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
