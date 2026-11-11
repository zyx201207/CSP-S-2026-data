#include<bits/stdc++.h>
using namespace std;
long long n,k;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long x;
	string c;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>c;
		while(x){
			s+=c;
			x--;
		}
	}
	for(long long i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])k++;
	}
	cout<<k;
	return 0;
}
