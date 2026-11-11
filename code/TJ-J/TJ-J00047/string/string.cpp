#include<bits/stdc++.h>
using namespace std;
char d[999999];
int s[999999];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,f=0;
	cin >> a;
	int g=(a-1)/2+1;
	int h=g-1,k=g+1;
	for(int i = 1;i <= a;i++)
	{
		cin >> s[i] >> d[i];
	}
	for(int j=(a-1)/2;j>0;j--)
	{
		if(a%2 != 0)
		{
			if(s[h]==s[k])
			{
				if(d[h]==d[k])
				{
					int z=0;
				}
				else
				{
					if(s[h]-s[k]<s[g])
					{
						f+=s[h]-s[k];
					}
					else
					{
				    	f+=s[g];
					}
				}
			}
			else
			{
				if(d[h]==d[k])
				{
					if(d[h]==d[g]==d[k])
					{
						
					}
					else if(s[h]>s[k] && s[h]-s[k]<s[g])
					{
						f+=s[h];
					}
					else if(s[h]<s[k] && s[k]-s[h]<s[g])
					{
						f+=s[k];
					}
					else
					{
						f+=s[g];
					}
				}
				else
				{
					if(s[h]>s[k] && s[h]-s[k]<s[g])
					{
						f+=s[h];
					}
					else if(s[h]<s[k] && s[k]-s[h]<s[g])
					{
						f+=s[k];
					}
					else if(s[h]>s[k] && s[h]-s[k]>s[g])
					{
						f+=(s[g]+s[k]);
					}
					else
					{
						f+=(s[g]+s[h]);
					}
				}
			}
		}
		else
		{
			
		}
		h--;
		g++;
	}
	cout << f;
	return 0;
}
