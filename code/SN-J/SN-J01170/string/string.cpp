//西安市高新第二初级中学 八年级16班 SN-J01170 杨博 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct zifu
{
	char s;
	long long cnt;
}ss[200005];
string as;
long long cnta;
long long l1,l2,r1,r2;
long long ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ss[i].cnt>>ss[i].s;
		for(long long j=0;j<ss[i].cnt;j++)
		{
			cnta++;
			as+=ss[i].s;
		}
	}
	r1=cnta%2==0?cnta/2-1:cnta/2;
	l2=cnta/2;
	l1=0;
	r2=cnta-1;
	while(l1<=r1&&l2<=r2)
	{
		if(as[r1]!=as[l2])
		{
			ans++;
		}
		r1--;
		l2++;
	} 
	cout<<ans;
	return 0;
}
