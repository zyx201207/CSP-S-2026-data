#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	longlong n;
	cin>>n;
	string s;
	longlong num=0;
	for(longlong i=0;i<n;i++)
	{
		longlong a;
		string c;
		cin>>a>>c;
		for(longlong j=0;j<a;j++)
		{
			s+=c;
		}
		num+=a;
	}
	longlong m=num/2;
	longlong x=num-1;
	longlong count=0;
		for(longlong i=0;i<m;i++)
		{
			if(s[i]==s[x])
			{
				x--;
			}
			else
			{
				count++;
				x--;
			}
		}
		cout<<count;
	return 0;
}
