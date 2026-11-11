#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		int num;string ts;
		cin>>num>>ts;
		for(int j=1;j<=num;j++)
		{
			s+=ts;
		}
	}
	int len=s.length();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i]) ans++;
	} 
	cout<<ans;
	 
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
