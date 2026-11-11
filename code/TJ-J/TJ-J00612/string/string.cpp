#include<bits/stdc++.h>
using namespace std;
int n;
long long a,num=0;
char b;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> b;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	int l=s.size();
	if(l%2==0)
	{
		int r=l-1,k=0;
		while(k<r)
		{
			if(s[k]!=s[r])
			{
				num++;
			}
			k++;
			r--;
		}
	}
	else
	{
		int r=l-1,k=0;
		while(r-k!=2)
		{
			if(s[k]==s[r])
			{
				
			}
			else
			{
				num++;
			}
			k++;
			r--;
		}
	}
	cout << num;
	return 0; 
}
