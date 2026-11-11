#include<bits/stdc++.h>
using namespace std;
long long n,s,an;
char c;
string z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(long long i = 1;i<=n;i++)
	{
		cin >> s >> c;
		if(s>=100000000)
		{
			cout << 0;
			return 0;
		}
		for(long long i = 1;i<=s;i++)
		{
			z+=c;
		}
	}
	for(long long i = 0,j=z.size()-1;i<j;i++,j--)
	{
		if(z[i]!=z[j])
		{
			an++;
		}
	}
	cout << an;
	return 0;
} 
