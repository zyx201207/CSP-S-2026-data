#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans=0;
string s="";
struct Node
{
	long long a;
	char c;
}k[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i].a>>k[i].c;
		for(int j=0;j<k[i].a;j++)
		{
			s+=k[i].c;
		}
	}
	for(int i=0;i<=(long long)s.size()/2-1;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
