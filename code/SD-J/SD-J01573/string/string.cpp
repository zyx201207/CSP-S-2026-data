#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],s1,u;
char b[100001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>b[i];
		s1+=a[i];
		for(int j = 1;j <= a[i];j++)
		{
			s+=b[i];
		}
	}
    for(int i = 1;i <= s1/2;i++)
    {
    	if(s[i-1] != s[s1-i])
    	{
    		u++;
		}
	}
	cout<<u;
}
