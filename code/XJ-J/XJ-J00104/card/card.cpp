#include<bits/stdc++.h>
using namespace std;
long long int ans[66],a[666666],b,n,m,i,t,v[666666],l,r;
deque <long long >q;
string s1,s2,s3,s4,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(i=1;i<=n;i++)
cin>>a[i];
for(t=1;t<=n;t++)
{
	q.clear();
	/*
	for(i=t;i<=n;i++)
	q.push_back(a[i]);
	for(l=t;l<=n;l++)
	{
		for(r=n;r>=l;r--)
		{
			if(a[l]==a[r])
			{
				r
			}
		}
	}
	*/
	l=t,r=n;
	while(l<=r&&l!=n)
	{
		if(a[l]==a[r])
		l=r,r=n;
		else
		r--;
		if(l==r)
		break;
	}
	for(i=l;i<=n;i++)
	{
		ans[a[i]]++;
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
}
for(i=1;i<=m;i++)
cout<<ans[i]<<" ";
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1


1
1
1 2
1
3 1 2 1
2 1
3 1 2 1
1 2
2 1
 



*/
