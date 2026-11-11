//All samples are accepted expect 100pts
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+20;
int n,a[N];char c[N];
long long sum,ans=0;
int main()
{
	// 务必删除注释！！！
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=1,r=n+1,y=0;// y残留部分 
	for(l=1;l<=r;l++)
	{
		if(y==0)  r--;
		else a[r]=y;
		if(r<=l)  break;
		long long cnt=0; //枚举了多少个字符 
		for(int j=r;;j--)
		{
			if(cnt+a[j]<a[l]) //加上此部分不够直接加 
			{
				cnt+=a[j];
				if(c[l]!=c[j])  ans+=a[j];
			}
			else
			{
				if(c[l]!=c[j])  ans+=(a[l]-cnt);
				y=a[j]-(a[l]-cnt);
				r=j;
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
