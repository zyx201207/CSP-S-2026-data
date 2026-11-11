/*
只能增大
考虑贪心
双指针扫区间后贪长度 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
typedef long long ll;
using namespace std;
ll n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=1,mij=0;//m[1,1] 
	while(r<=n)
	{
		r++;
		mij=(a[r]-a[r-1])*(r-l)+mij;
//		cout<<"m["<<l<<","<<r<<"]="<<mij<<'\n';
		while(mij>m)//多出去了
		{
			l++;//收左端点
			mij=mij-(a[r]-a[l-1]); 
			if(r<l)//区间长度不足1
			{
				mij=0;
				r=l;
				//将r移到l处，重置长度与m值 
			} 
		} 
		ans=max(ans,r-l+1);
	} 
	cout<<ans<<'\n'; 
	return 0;
}
