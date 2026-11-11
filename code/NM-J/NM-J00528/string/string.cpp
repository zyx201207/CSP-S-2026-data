#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int he=0,n,a[200005];
	string c[200005];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		int l=a[i];
		for (int j=1;j<=l;j++)
		{
			s=s+c[i];
		}
	}
	int len=s.size();
	string ss;
	for (int i=n;i>=1;i--)
	{
		int l=a[i];
		for (int j=1;j<=l;j++)
		{
			ss=ss+c[i];
		}
	}
	if (s==ss) cout<<'0';
	else
	{
		int i=1,j=s.size();
		while(i<j)
		{
			if (s[i]==s[j]){
								i++;
								j--;
						   }
					else{
							i++;
							j--;
							he++;
						}
		}
	}
	cout<<he;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
