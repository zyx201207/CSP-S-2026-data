#include<bits/stdc++.h>
using namespace std;
int n,sum=0,a[2100005];
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	long long slen=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c;
		for(int j=slen;j<slen+a[i];j++)s[j]=c;
		slen+=a[i];
	}
	int k=1;
	for(int i=0;i<=slen/2;i+=a[k])
	{
		if(s[i+min(a[k],a[n-k])]!=s[n-min(a[k],a[n-k])])sum+=min(a[k],a[n-k]);
		k++;
	}
	cout<<sum;
	return 0;
 } 
