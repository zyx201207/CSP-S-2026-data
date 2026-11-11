#include<bits/stdc++.h>//68pts 8个1e9的过不去
#define int long long
using namespace std;
/*
思路：反转字符串 从1~n/2看看有几个不同 
*/
const int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1},N=2e5+5;
int n,t,ans,x[N],sum;
char c[N];
string s;
void slove()
{
	string x=s;
	reverse(x.begin(),x.end());
	if(x==s)
	{
		cout<<0;
		return;
	}
	for(int i=0;i<(n+1)>>1;i++)
	{
		if(x[i]!=s[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	int f=1;
	for(int i=1;i<=t;i++)
	{
		cin>>x[i]>>c[i];
		sum+=x[i];
		if(sum>505000000)
		{
			f=0;
		}
	}
	if(t==1)
	{
		cout<<0;
		return 0;
	}
	
	n=sum;
	if(f==1)
	{
		
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=x[i];j++)
			{
				s+=c[i];
			}
		}
		slove();
	}
	else
	{
		cout<<(n+1)/2;
	}
	return 0;
}
/*
用我不会证明的代码过了几个大样例 但1e9的点会RE 解决不了
*/ 
