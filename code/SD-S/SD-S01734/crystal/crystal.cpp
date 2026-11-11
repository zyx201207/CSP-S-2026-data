/*I Used To Recall The Back*/
/*RP++*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long int n,m,a[MAXN];
long long int ans=0;
bool special=1;//是否是等差数列
long long int s=0; //等差数列公差 
void solve()//爆搜
{
	//枚举最终所达成一致的值
	for(int i=n;i>=2;i--) 
	{
		long long int pos=i-1;
		long long int tmp=1,tm=m;//tmp是本次的ans,tm是用来代替m的 
		while(1) 
		{
			long long diff=a[i]-a[pos];
			if(diff>tm||pos==0)
			{
				break;
			}
			tmp++;
			tm-=diff;
			pos--;
		}
		ans=max(ans,tmp);
	}
}
int main()//16:33   75分到手 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2)
		{
			s=a[i]-a[i-1];
		}
		if(i>2&&a[i]-a[i-1]!=s)
		{
			special=0;
		}
	}
	sort(a+1,a+n+1);
	if(special)//特殊性质 
	{
		ans=(m/(2*s))+1;
	}
	else//没特殊性质 
	{
		solve();
	}
	printf("%d",ans);
	return 0;
}
