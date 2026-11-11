#include <bits/stdc++.h>
using namespace std;
const long long N=200005;
long long n,cnt;
struct node
{
	long long len;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i].len>>a[i].c;
	for(long long l=1,r=n;l<=r;)
	{
		long long minn=min(a[l].len,a[r].len);
		if(a[l].c!=a[r].c)
			cnt+=minn;
		a[l].len-=minn,a[r].len-=minn;
		if(a[l].len<=0)
			l++;
		if(a[r].len<=0)
			r--;
	}
	cout<<cnt;
	return 0;
}
/*
昵称：元耀mark（洛谷zyx0326) 
性别：男
年龄：12 
考点：山东外国语职业技术大学 
学校：你猜
年级：初一
着装：白灰色外套，金属框眼镜 
成分极其复杂 
*/ 
