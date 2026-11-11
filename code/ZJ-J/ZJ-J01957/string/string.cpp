#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,j,a[200005],s=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	i=1;
	j=n;
	while(i<j)
	{
		if(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				s+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else if(a[i]==a[j])
		{
			if(c[i]!=c[j])s+=a[i];
			a[i]=a[j]=0;
			i++;
			j--;
		}
		else
		{
			if(c[i]!=c[j])
			{
				s+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<s;
	return 0;
}
/*

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c


*/