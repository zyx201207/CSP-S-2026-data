//I'm SD-J00440
//I just a junior middle school student so CSP-S is too hard for me
//qwq
//3= please

/*

After CSP 2026 I will AFO,
the end of my OI life during junior middle school.
A dream?

All right.
Let's meet at high middle school again, OI.
Then I will get S prize and NOIP prize!

Now, OI,

it's time to say goodbye.

Remember, not the end, never the end. 

orz

2026.10.31 18:04
cxk_ctrl


maybe I will learn CTF after AFO (

*/

#include<bits/stdc++.h>
#define debug cout<<"___________________"<<endl
#define int long long
using namespace std;
int a[500010];
int n,m;
int d[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	else if(n==2)
	{
		if(a[1]>=a[2]&&a[2]>0&&m>=abs(a[1]-a[2]))
		{
			cout<<"2";
		}
		else if(a[2]>=a[1]&&a[1]>0&&m>=abs(a[1]-a[2]))
		{
			cout<<"2";
		}
		else if(a[1]<0&&a[2]<0&&m>=abs(abs(a[1])-abs(a[2])))
		{
			cout<<"2";
		}
		else if(a[1]<0&&a[2]>=0&&a[1]+m>=a[2])
		{
			cout<<"2";
		}
		else if(a[2]<0&&a[1]>=0&&a[2]+m>=a[1])
		{
			cout<<"2";
		}
		else 
		{
			cout<<"1";
		}
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==0)
	{
		int sum=1,maxsum=1;
		bool flag=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				if(!flag)flag=1;
				sum++;
			}
			maxsum=max(maxsum,sum);
			if(flag==1&&a[i]!=a[i+1])
			{
				flag=0;	
				sum=1;
			}
		}
		cout<<maxsum;
		return 0;
	} 
	else // 可以搞定等差数列 
	{
		int ans;
		for(int i=n;i>=1;i--)
		{
			d[i]=a[n]-a[i]+d[i+1];
			if(d[i]>m)
			{
				ans=n-i;
				break;
			}
			else if(i==1&&d[1]<=m)
			{
				ans=n;
			}
			//cout<<endl<<"debug:i="<<i<<" a[i]="<<a[i]<<" d[i]="<<d[i]<<endl;
		}
		cout<<ans;
		//d[i]表示让第i位符合的总开销 
		/*
		int pos=n-1,sum=1;
		while(m>0)
		{
			if(a[1]==a[n])
			{
				cout<<n;
				return 0;
			}
			if(a[pos]!=a[n])
			{
				m--;
				a[pos]++;
			}
			else
			{
				sum++;
				pos--;
			}
		}
		cout<<sum;
		*/
		
	}
	return 0;
}

//注意到：存在 n=1 和 m=0 且 m<=10^18 
//同时答案必定为正整数 
//m不一定全部使用, 负数也可以合并 
/*
转化为数学问题： 
现给出降序数组a，含n元素，a_i即所对应权值 
至多修改m次，每次修改可使任意一位权值+1
最大化【至多m次】修改后权值相同的元素个数
*/

//请输入文本 
