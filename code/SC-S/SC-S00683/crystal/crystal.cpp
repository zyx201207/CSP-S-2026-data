#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
int a[500005],p[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int k=m,sum=0;
	bool bol=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) bol=0;
	}
	if(bol)
	{
	int ans=1;
	int l=1,r=1;
		while(r<=n&&l<=r)
		{
			int x=(l+r)/2;
			int cntt=(r-x)*(r-x+1)/2+(x-l)*(x-l)+1/2;
			if(k<cntt) l++;
			else r++;
			ans=max(ans,r-l);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int ans=1;
	int l=1,r=1;
	while(r<=n&&l<=r)
	{
		int cntt=100000000000;
        int i=a[r];
//			int ll=l,rr=r;
//			while(ll<=rr)
//			{
//				int mid=(ll+rr)/2;
//				if(a[mid]<i)
//				{
//					ll=mid+1;
//				}
//				else
//				{
//					rr=mid-1;
//				}
//			}
//			cout<<l<<" "<<r<<" "<<ll<<endl;
//			cout<<(ll-1)*i<<" "<<(q[ll-1]-q[l-1])<<" "<<q[r]-q[ll-1]<<" "<<endl;
//			int cnt1=(ll-1)*i-(q[ll-1]-q[l-1]);
//			int cnt2=q[r]-q[ll-1]-(ll-1)*i;
//			int cnt=cnt1+cnt2;
//			cout<<"!"<<cnt<<endl;
			int cnt=0;
			for(int j=l;j<=r;j++)
			{
				cnt+=abs(a[j]-i);
			}
			cntt=min(cnt,cntt);
//		cout<<cntt<<" ";
		if(k<cntt) l++;
		else r++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}  
