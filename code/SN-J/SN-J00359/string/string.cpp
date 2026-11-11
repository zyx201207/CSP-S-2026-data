#include<bits/stdc++.h>
#define PI "string"
#define FI freopen(PI".in","r",stdin)
#define FO freopen(PI".out","w",stdout)
#define  ll long long
using namespace std;
const int N=2e5;
ll n,a[N],ans;
string s;
char c;
bool hwcheck(string s)
{
	int l=s.size(),j=l/2+1;
	for(int i=l/2-1;i>=0;i--)
	{
		if(s[i]!=s[j]) return false;
		j++;
	}
	return true;
}
int main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	int l=s.size();
	if(hwcheck(s))
	{
		cout<<"0";
		return 0;
	}
	int j=l/2+1;
	for(int i=l/2-1;i>=0;i--)
	{
		if(s[i]!=s[j])	ans++;
		j++;
	}
	cout<<ans;
	return 0;
}
