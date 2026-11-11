#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s = "";
    for(int i = 1;i<=n;i++)
    {
    	long long x;
    	char y;
    	cin >> x >> y;
    	for(int j = 1;j<=x;j++)
    	{
    		s+=y;
		}
	}
	long long sum=0;
	for(int i = 0;i<=s.length()/2-1;i++)
	{
		if(s[i]!=s[s.length()-1-i])
		{
			sum++;
			s[i]=s[s.length()-1-i];
		}
	}
	cout << sum;
	return 0;
}
