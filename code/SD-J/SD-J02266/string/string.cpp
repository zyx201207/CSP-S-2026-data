#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n=0,m,tot=0;
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		n += a[i];
	}
	ll change=0,com=0;
	for (int i=1,j=m,l=1,r=n;com<n/2 && i<j;)
	{
		change = min(a[i],a[j]);
		a[i] -= change;
		a[j] -= change;
		com += change;
		if (b[i]!=b[j])
		{
			tot += change;
		}
		if (a[i]==0) i++;
		if (a[j]==0) j--;
	}
	cout<<tot;
	return 0;
} 
