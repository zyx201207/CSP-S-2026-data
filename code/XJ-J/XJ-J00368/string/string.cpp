#include<bits/stdc++.h>
using namespace std;
long long a,b,d=0,e=0;
char c,s[100000000005]={};
int main()
{
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
    cin>>a;
    for(int i;i<a;i++)
    {
    	cin>>b;
    	cin>>c;
    	for(int j=0;j<b;j++)
    	{
    		s[d]=c;
    		d++;
		}
	}
	for(int i=d/2-1;i>=0;i--)
	{
		for(int j=d/2;j<d;j++)
		{
			if(s[i]!=s[j])
			{
				e++;
			}
		}
	}
	cout<<e/3;
}