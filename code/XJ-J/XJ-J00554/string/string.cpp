#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,num;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	if(num%2==0)
	{
		int l=num/2-1;
		int r=num/2;
		if(s[l]!=s[r])
		{
			ans++;
		}
		for(int i=1;i<=l;i++)
		{
			if(s[l-i]!=s[r+i])
			{
				ans++;
			}
		}
	}
	else
	{
		int mid=num/2;
		for(int i=1;i<=mid;i++)
		{
			if(s[mid-i]!=s[mid+i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
return 0;
}