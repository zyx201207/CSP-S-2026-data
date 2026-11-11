//SN-J00773 林靖轩 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans=0;
string s;
int a[N];
char c[N];
signed main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
				a[l]-=a[r],ans+=a[r],r--;
			else if(a[l]<a[r])
				a[r]-=a[l],ans+=a[l],l++;
			else if(a[l]==a[r])
				ans+=a[l],l++,r--;
		}
		else if(c[l]==c[r])
		{
			if(a[l]>a[r])
				a[l]-=a[r],r--;
			else if(a[l]<a[r])
				a[r]-=a[l],l++;
			else if(a[l]==a[r])
				l++,r--;
		}
	}
	cout<<ans;
	return 0;
}

