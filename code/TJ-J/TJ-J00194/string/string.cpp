#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a,ans,x;
string s;
char c;
int main()
{
	freopen("string.in",'r',"stdin");
	freopen("string.out",'w',"stdout");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>c;
		x+=a;
		for (int i=1;i<=a;i++) s+=c;
	}
	for (int i=0;i<=x/2;i++)
		if (s[i]!=s[x-i-1]) ans++;
	cout<<ans;
	return 0;
}
