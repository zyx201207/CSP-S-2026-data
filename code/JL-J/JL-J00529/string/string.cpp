/*luogu 1842302
why T2 dp??
5555
only 16pts
 I am very sad because I forget the zui chang gong gong zi xv lie 
 so 48->16
*/ 
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	char ch;
};
node s[200001];
int dp[10001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int maxa=-0x3f3f3f3f;
	long long suma=0;
	for(int i=1;i<=n;i++)
	{
		int q;
		char cc;
		cin>>q>>cc;
		maxa=max(q,maxa);
		s[i].num=q;
		s[i].ch=cc;
		suma+=q;
	}
	if(n==1) //#1 0854
	{
		cout<<0;
		return 0;
	}
	if(n==2)//#2 3 4 0902
	{
		cout<<min(s[1].num,s[2].num)<<endl;
		return 0;
	}
	string ss="";
	if(suma<=1e4)// fail 1003
	{	memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=s[i].num;j++) ss+=s[i].ch;
		}
		string st="";
		for(int i=suma-1;i>=0;i--) st+=ss[i];
		if(ss[0]==st[0])
		for(int i=0;i<suma;i++)
		{
			for(int j=i;j<suma;j++)
			{
				if(ss[i]==st[j]) dp[j]=max(dp[j],dp[i]+1);
				else dp[j]=max(dp[j],dp[i]);
			}
		}
		cout<<suma-dp[suma-1]<<endl;
		return 0;
	}//may be wrong DP
	cout<<0;
	return 0;
}
