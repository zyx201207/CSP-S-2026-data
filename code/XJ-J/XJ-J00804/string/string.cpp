#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,x=0;
	char c;
	string s="\0";
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>c;
		for(long long j=0;j<a;j++)
		{
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2+1;i++)
	{
		if(s[i]!=s[s.size()-1-i])x++;
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}