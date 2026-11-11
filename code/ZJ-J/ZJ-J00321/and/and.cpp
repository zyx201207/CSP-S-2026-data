#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//freopen
//freopen
//RP++
//Let me AK CSP-J pls CCF!!!
//I am lsc from Zhejiang Cixi
//I will AFO tomorrow
//I think I can do nothing but AK CSP-J
//I like Mc,pvz,florr
//My mace pvp is HT6
//My florr is lv122 and 2 Super
//if you want to give me a message
//send to luogu.com.cn,my user name is 123lusicheng
//I think it is good to write a poem now
/*
     AFO
颓废，很快乐
退役，很快了
抓住机会吧，
下一代OIer.
不要颓废，
我已经吃到了苦头
努力学习，
现在只剩下这条路
如果你要颓废，
请不要学编程。
浪费时间，
这并不好
	  -123lusicheng 2026.10.31考场作 
*/
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
int n,m,i,a[200005],j;
long long ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(i=31;i>=0;i--)
	{// from 31~0 to check the i can or cant be 1
		int cnt=0;
		for(j=n;j>=1;j--)
		{
			if(a[j]<ans)break;
			if((a[j]>>i)&1)cnt++;
		}
		if(cnt>=m)ans+=(1<<i);
	}
	printf("%lld",ans);
	return 0;
}
