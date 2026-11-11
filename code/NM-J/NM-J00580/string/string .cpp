#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],ans;
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=0;i<a[i];i++)
		s+=c[i]; 
	for(int i=0;i<s.size();i++)
	{
		for(int j=s.size()-1;j>=0;j--)
		{
			if(s[i]!=s[j])ans++;
					else continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
