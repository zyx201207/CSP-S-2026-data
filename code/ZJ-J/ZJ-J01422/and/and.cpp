#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
string c[200002];
long long n,m;
long long a[200002];
long long box[35];
bool flag;
unsigned long long ans=(1<<30)-1;
bool cmp(long long x,long long y)
{
	return x>y;
}
struct Node
{
	string s;
	long long b;
}xx[200002];
bool cmp2(Node kk,Node bb)
{
	return kk.s>bb.s;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
//	cout<<(char)65<<endl;
//	cout<<200002*35<<endl;
//	freopen("and3.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		xx[i].b=a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long x=a[i];
		for(long long j=0;j<=31;j++)
		{
			c[i]=((char)((x&1)+'0'))+c[i];
			if(x&1==1)
			{
				box[31-j]++;
			}
			x>>=1;
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<c[i]<<endl;
//	}
	for(long long i=0;i<=31;i++)
	{
		if(box[i]>=m&&!flag)
		{
//			cout<<i<<" "<<box[i]<<endl;
			flag=1;
			for(long long j=1;j<=n;j++)
			{
				if(c[j][i]=='1')
				{
//					cout<<j<<endl;
					for(long long k=i;k<c[j].size();k++)
					{
						xx[j].s=xx[j].s+c[j][k];
					}
				}
			}
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<xx[i].s<<endl;
//	}
	sort(xx+1,xx+n+1,cmp2);
//	cout<<ans<<endl;
	for(long long i=1;i<=m;i++)
	{
		ans&=xx[i].b;
//		cout<<xx[i].s<<" "<<xx[i].b<<endl;
	}
	cout<<ans<<endl;
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<s[i]<<endl;
//	}
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<c[i]<<endl;
//	}
	return 0;
}
/*
9:24 kan ti
zen me you dian xiang qu nian ba wo zhe mo si de T3...wo yao ku le...
qu nian yi huo he,jin nian an wei yu...xiang zen yang!TT
9:31 si hu ke yi zhi jie jin zhi zhuan huan ne^^
9:55 chu qu shang le ge ce suo...dang shi zai ge jian men kou zhan le yi hui yin wei shi zai tai chou le...yi ge jian kao lao shi jin lai yi wei wo zai zuo bi...zhe qi shen le...zui hou ba kou dai dou gei wo tao le yi bian.
4 2
3 15 12 12
10:38 guo suo you da yang li le.wo zhen bang!!!
ben lai yi wei chang qie bu liao T3 le lai zhe^_^

CCF I LOVE YOU
*/