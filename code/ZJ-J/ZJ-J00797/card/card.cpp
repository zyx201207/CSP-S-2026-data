#include<bits/stdc++.h>//40pts
#define int long long
using namespace std;
/*
思路：前24分模拟n3 特殊A遍历a做统计有几个数 再前缀
特殊B暂无思路 
*/
const int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1},N=5e5+5;
int n,m,a[N],A=1,hz[N];
stack<int>st;
map<int,int>mp,bj,mpa;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			if(a[i]>a[i-1])
			{
				A=0;
			}
		}
	}
	if(A==1)//special A
	{
		hz[n]=1;
		for(int i=1;i<=n;i++)
		{
			mpa[a[i]]++;
		}
		for(int i=2;i<=m;i++)
		{
			mpa[i]+=mpa[i-1];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<mpa[i]<<" ";
		}
		return 0;
	}
	else if(m<=2)
	{
		if(m==1)
		{
			cout<<n;
		}
		else
		{
			int lx2=0,lx1=0;
			for(int i=n;i>=1;i--)
			{
				if(a[i]==2)
				{
					lx2++;
				}
				else
				{
					break;
				}
			}
			for(int i=n;i>=1;i--)
			{
				if(a[i]==1)
				{
					lx1++;
				}
				else
				{
					break;
				}
			}
			if(lx1==0)
			{
				lx2--;
			}
			else if(lx2==0)
			{
				lx1--;
			}
			cout<<n-lx2<<" "<<n-lx1;
		}
		return 0;
	}
	for(int k=1;k<=n;k++)//24
	{
		bj.clear();
		for(int i=k;i<=n;i++)
		{
			bj[a[i]]++;
			if(bj[a[i]]==2)//重复了
			{
				while(1)
				{
					int u=st.top();
					st.pop();
					if(u==a[i])
					{
						break;
					}
				}
				bj[a[i]]--;
				
			}
			st.push(a[i]);
		}
		while(!st.empty())
		{
			mp[st.top()]++;
			st.pop();
		}
//		for(int i=1;i<=m;i++)
//		{
//			cout<<mp[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<" ";
	}
	return 0;
}
/*
可能和一等无缘了
T1 100pts
T2 68pts 估计只有50 会爆栈 会RE TLE
T3 60pts B想不出来应该会TLE
T4 40pts B性质想不出来 会TLE
还有这个电脑有些大样例记事本打开是乱码 要用写字板 神了
估分220
T2挣扎一下 
二等吧
*/ 
