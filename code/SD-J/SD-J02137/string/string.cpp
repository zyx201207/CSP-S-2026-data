#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,l,cnt;
vector<int> a;
char c[20005];
string s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a.assign(n+1,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;) 
	{
		int num;
		num=min(a[i],a[j]);
		if(c[i]!=c[j]) cnt+=num;
		a[i]-=num;
		a[j]-=num;
		if(a[i]==0) i++;
		else j--;
	}
	cout<<cnt;
 } 

