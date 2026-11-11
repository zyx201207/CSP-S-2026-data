#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m;
long long a[500005];
long long ji(int x){
	int i=1;
	while(a[i]<=x) i++;
	ll sum=0,cnt=0;
	i-=1;
	while(sum+x-a[i]<=m&&i>0){
		sum+=x-a[i];
		i--;
		cnt++;
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll minn=4e18,maxx=-4e18;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	long long l=a[(1+n)/2],ans=-1;
	for (int i=minn;i<=maxx;i++){
		ans=max(ji(i),ans);
	}
	cout<<ans<<'\n';
	return 0;
} 
//初中生误入高端局
//他们怎么都那么能写
//就我一个人在打牌
//金字塔2万分什么实力我不多说了 
//刚刚监考老师瞄了我一眼
//吓我一跳 
//就第一题能看懂
//234题是人能做的吗 
