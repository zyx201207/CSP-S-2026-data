#include<bits/stdc++.h>
using namespace std;
bool b[200009][32];
bool flag[200009];
int maxlen = -1;
void trans(int id,int num)
{
	for(int i =1;i<=30;i++)
	{
		if(num ==0)
		{
			b[id][i]= false;
			continue;
		}
		if(num %2 == 1)
		{
			b[id][i]= true;	
			if(i> maxlen) maxlen=i;
		}
		num >>=1;
	}
}
int main()
{	 
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	int c_num;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c_num);
		trans(i,c_num);
		flag[i] = true;
	}
	int ct,times=1;
	int s,q[200009];
	for(int i=2;i<=maxlen;i++)
	{
		times*=2;
	}
	for(int i = maxlen;i>=1;i--)
	{
		ct=0,s=0;
		for(int j = 1;j<=n;j++)
		{
			if(flag[j] and b[j][i]) ct++;
			else 
			{
				q[s]=j;
				s++;
			}
		}
		if(ct >= m)
		{
			for(int j = 0;j<s;j++)
				flag[q[j]] = false;
			ans+=times;
		}
		times>>=1;
	}
	printf("%d",ans);
	return 0;
}
