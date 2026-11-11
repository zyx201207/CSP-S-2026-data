#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,a[N],l1,r1;
char c[N];
long long l,r,all,mid,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		all+=a[i];
		cin>>c[i];
	}
	mid=all/2,l1=0,r1=n+1;
	while(true)
	{
		if(l==r) l+=a[++l1];
		while(r<l&&r<mid)
		{
			r+=a[--r1];
			if(c[r1]!=c[l1]) ans+=min(min(l,r),mid)-max(l-a[l1]+1,r-a[r1]+1)+1;
		}
		while(r>l&&l<mid)
		{
			l+=a[++l1];
			if(c[r1]!=c[l1]) ans+=min(min(l,r),mid)-max(l-a[l1]+1,r-a[r1]+1)+1;
		}
		if(l>=mid&&r>=mid) break;
	}
	cout<<ans;
 	return 0;
}
