#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[500005],s[500005];
//bool check(int x)
//{
//	for(int i=1;i<=n-x;i++)
//	{
//		int cur=s[x+i-1]-s[i-1];
//		cur-=a[i]*x;
////		cerr<<cur<<endl;
//		//the only problem will be on my checking function
//		if(cur<=m)return true;
//	}
//	return false;
//}
//why WA? 
//I think I don't have to make another function
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++)cerr<<s[i]<<' ';
//  cerr<<endl;
//	sort?   X(no need in examples)
//	but sort seems to be important
	int l=0,r=n,ans;
	while(l<r)
	{
		int mid=(l+r)/2;
//		cerr<<l<<" "<<mid<<" "<<r<<endl;
		if(a[mid]*mid-s[mid]<=m)//Just made it in main()
			l=mid+1,ans=mid;
		else r=mid-1;
		//maybe ranges prblem?
	}
	cout<<ans<<endl;
	return 0;
}
//oh I'm too stupid to use freopen to examine my code

