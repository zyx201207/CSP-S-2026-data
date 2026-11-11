#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
ll a[N],sum;
char ch[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]==a[r])
		{
			if(ch[l]!=ch[r]) sum+=a[l];
			l++;
			r--;
		}
		else if(a[l]<a[r])
		{
			if(ch[l]!=ch[r]) sum+=a[l];
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(ch[l]!=ch[r]) sum+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
