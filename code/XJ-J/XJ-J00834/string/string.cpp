#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll ans=0,cnt=0,idx1=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	ll n,a[N];
	char b[N];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	idx1=cnt/2;
	ll idx2=idx1; 
	int l=1,r=n;
	while(l<=r)
	{
		if(a[l]<=a[r])
		{
			idx1-=a[l];
			idx2-=a[l];
			if(b[l]!=b[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
			
			
		}
		if(a[l]>a[r])
		{
			idx1-=a[r];
			idx2-=a[r];
			if(b[l]!=b[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
			
		}		
		
		
	}
	cout<<ans;
	return 0;
}
