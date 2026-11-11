#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
	int a;
	char x;
}s[N];
long long q[N];
int n;
int ans;
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].x;
		for(int j=1;j<=s[i].a;j++)str+=s[i].x;
	}
	for(int i=0;i<=str.size()/2;i++)if(str[i]!=str[n-i])ans++;
	cout<<ans;
	return 0;
}
