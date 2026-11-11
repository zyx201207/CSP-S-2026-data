#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
struct fnt
{
	int num;
	char c;
};
fnt a[N],rev[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		len+=a[i].num;
	}
	for(int i=1;i<=n;i++)
	{
		rev[i].num=a[n-i+1].num;
		rev[i].c=a[n-i+1].c;
	}
	//len/2
	int lenf=0/*,lenb=0*/,lastb=0,bgn=1,lmt=len/2,ans=0;//front back
	//lastb:rev中残留的长度 bgn:下一次从rev的哪里开始搜索 
	//需要保证lenb==lenf 
	for(int i=1;i<=n;i++)
	{
		int num=a[i].num;
		char c=a[i].c;
		if(lenf+num<=lmt)//可以完全搜索a[i] 
		{
			lenf+=num;
			if(lastb>0)
			{
				//cout<<i<<" "<<lastb<<endl;
				if(num<lastb)
				{
					if(c!=rev[bgn-1].c) ans+=num;
					lastb-=num;
					//lenb+=num;
				}
				else //能完全去除lastb 
				{
					if(c!=rev[bgn-1].c) ans+=lastb;
					num-=lastb; //lenb+=lastb;
					lastb=0;
					
					for(int j=bgn;j<=n;j++)
					{
						//cout<<i<<" "<<j<<" "<<num<<" ren[j].num"<<rev[j].num<<endl;
						if(num>rev[j].num)//完全 
						{
							if(c!=rev[j].c) ans+=rev[j].num;
							num-=rev[j].num;
							bgn++;
							//lenb+=rev[j].num;
						}
						else
						{
							bgn++;
							lastb=(rev[j].num-num);
							if(c!=rev[j].c) ans+=num;
							num=0;
							break;
						}
					}
				}
			}
			else//lastb==0
			{
				for(int j=bgn;j<=n;j++)
				{
					if(num>rev[j].num)//完全 
					{
						//cout<<i<<" num:"<<num<<endl;
						if(c!=rev[j].c) ans+=rev[j].num;
						num-=rev[j].num;
						bgn++;
						//lenb+=rev[j].num;
					}
					else
					{
						//cout<<i<<" num:"<<num<<endl;
						bgn++;
						lastb=(rev[j].num-num);
						if(c!=rev[j].c) ans+=num;
						num=0;
						break;
					}
				}
			}
		}
		else//不可以完全搜索a[i] 
		{
			num=lmt-lenf;
			if(lastb>0)
			{
				if(num<lastb)
				{
					if(c!=rev[bgn-1].c) ans+=num;
					lastb-=num;
					//lenb+=num;
				}
				else
				{
					if(c!=rev[bgn-1].c) ans+=lastb;
					num-=lastb; //lenb+=lastb;
					lastb=0;
					
					for(int j=bgn;j<=n;j++)
					{
						if(num>rev[j].num)//完全 
						{
							if(c!=rev[j].c) ans+=rev[j].num;
							num-=rev[j].num;
							bgn++;
							//lenb+=rev[j].num;
						}
						else
						{
							bgn++;
							lastb=(rev[j].num-num);
							if(c!=rev[j].c) ans+=num;
							num=0;
							break;
						}
					}
				}
			}
			else
			{
				for(int j=bgn;j<=n;j++)
				{
					//cout<<i<<" num:"<<num<<endl;
					if(num>rev[j].num)//完全 
					{
						if(c!=rev[j].c) ans+=rev[j].num;
						num-=rev[j].num;
						bgn++;
						//lenb+=rev[j].num;
					}
					else
					{
						//cout<<i<<" num:"<<num<<endl;
						bgn++;
						lastb=(rev[j].num-num);
						if(c!=rev[j].c) ans+=num;
						num=0;
						break;
					}
				}
			}
			break;
		}
		//cout<<i<<" "<<lenf<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
10
3 h
1 k
3 o
2 n
2 m
1 f
3 d
1 p
1 p
3 c
*/
