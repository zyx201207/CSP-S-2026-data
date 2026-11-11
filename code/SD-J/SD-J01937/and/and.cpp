#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,num;
long long sr,ans,ans2[30];
bool bj[N][35],flag;
bool choice[N],max_ans[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ans2[0]=1;
	for(int i=1;i<=30;i++)
		ans2[i]=2*ans2[i-1];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sr);
		int wz=0;
		while(sr)
		{
			num=sr%2;
			if(num)
				bj[i][wz]=1;
			sr/=2;
			wz++;
		}
	}
	flag=1;
	memset(max_ans,1,sizeof(max_ans));
	for(int i=30;i>=0;i--)
	{
		num=0;
		for(int j=1;j<=n;j++)
		{
			if(max_ans[j]&&bj[j][i])
			{
				choice[j]=1;
				num++;
			}
		}
		if(num>=m)
		{
			ans+=ans2[i];
			if(flag)
			{
				for(int j=1;j<=n;j++)
					max_ans[j]=choice[j];
				flag=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
