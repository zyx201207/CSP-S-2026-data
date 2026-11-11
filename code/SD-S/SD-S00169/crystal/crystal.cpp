#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],cnt=1,k,ans=1,x,cost[500005];//x是求最长连续值相等的字串的临时变量
int n,pos=1,q;
bool flag=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	k=a[2]-a[1];
	if(m==0)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
				x++;
			else
				ans=max(ans,x),x=1;
		}
		cout<<ans;
		return 0; 
	}
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1])
		{
			flag=0;
			break;//无用的小优化
		}
	}
	if(flag)//特殊性质A&B(似乎B的代码也可以实现A所以合并为一段代码)
	{
		while(1)//我不会告诉你我写while(1)的原因是我只会for不会while
		{
			if(m-k>=0)
			{
				m-=k;
				cnt++;
				k+=a[2]-a[1];
			}
			else
				break;
		}
		cout<<cnt;
	}
	else//无特殊性质不会只能瞎写
	{
		for(int i=2;i<=n;i++)//想法:把m=0的特判抄过来，再往下一个个扣，不过似乎也不太对，当ans的数略大于第二，且m的值有能满足填充多个第二会炸吧，算了没啥想法去看T2吧
		{//看完T2感觉自己像大愚弱智，通读了一遍卷子发现只有T1长得眉清目秀，回来打吧
			if(a[i]==a[i-1])
				x++;
			else
				cnt=max(cnt,x),x=1,ans=a[i-1];//cnt是计数器用于计量数量最多的值的数量，ans是数量最多的值
		}
		if(cnt==1)//所有数据均不重复
		{
			//cout<<a[(n+1)/2]-1;//不会所以瞎写
			ans=1;
			for(int i=2;i<=n;i++)//以a[i]作为基准枚举答案
			{
				q=i-1,cnt=1;
				while(1)
				{
					if(m-a[i]+a[q]>=0)
					{
						m-=a[i]-a[q];
						cnt++,ans=max(ans,cnt),q--;
					}
					else
						break;
				}
			}
			cout<<ans-1; 
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==ans)
				{
					pos=max(i-1,1);//神秘无用小巧思
					break; 
				}
			}
			while(1)
			{
				if(m-ans+a[pos]>=0)
				{
					m-=ans-a[pos];
					cnt++,pos--;
				}
				else
					break;
			}
			cout<<cnt;
		}
	}
	return 0;
}
