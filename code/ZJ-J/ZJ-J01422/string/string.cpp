#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
long long n;
long long num[200002];
char c[200002];
long long sum;
string s;
long long ans;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
//	cout<<LLONG_MAX<<endl;
//	freopen("string4.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>num[i]>>c[i];
//		sum+=num[i];
//		num[i]=sum;
	}
	long long l=1,r=n;
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<num[i]<<endl;
//	}
	while(l<r)
	{
//		cout<<l<<" "<<r<<endl;
		if(c[l]!=c[r])
		{
			ans+=min(num[l],num[r]);
//			cout<<ans<<endl;
//			cout<<num[l]<<" "<<num[r]<<endl;
		}
		if(num[l]<num[r])
		{
			num[r]-=num[l];
			num[l]=0;
			l++;
		}
		else if(num[l]==num[r])
		{
			num[l]=0,num[r]=0;
			l++,r--;
		}
		else if(num[l]>num[r])
		{
			num[l]-=num[r];
			num[r]=0;
			r--;
		}
	}
//	cout<<sum<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
8:47 kan ti
8:54 si hu mei shen me si lu?
si hu shi shuang zhi zhen
9:01 guo xiao yang li le
wo de da yang li ne?
9:05 zhong yu ba wen jian dou xia xia lai le...
9:10 wan dan le da yang li si le
3
1 a
2 b
3 a
ying gai shi 2
9:22 guo le...gan jue zi ji hao sha...

CCF I LOVE YOU
*/