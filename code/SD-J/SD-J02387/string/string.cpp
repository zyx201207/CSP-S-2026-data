#include<bits/stdc++.h>
using namespace std;
int ch(char a)
{
	if(a=='a') return 1;if(a=='b') return 2;if(a=='c') return 3;if(a=='d') return 4;if(a=='e') return 5;if(a=='f') return 6;if(a=='g') return 7;if(a=='h') return 8;if(a=='i') return 9;if(a=='j') return 10;if(a=='k') return 11;if(a=='l') return 12;if(a=='m') return 13;if(a=='n') return 14;if(a=='o') return 15;if(a=='p') return 16;if(a=='q') return 17;if(a=='r') return 18;if(a=='s') return 19;if(a=='t') return 20;if(a=='u') return 21;if(a=='v') return 22;if(a=='w') return 23;if(a=='x') return 24;if(a=='y') return 25;if(a=='z') return 26;
	//da biao wu yi shi hao fei xan shi shi jian huan yun xing shi jian
	//O(1)da cha zhao you mei you dong de
}

struct nood
{
	long long a;
	char c;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s[0].a=0;
	s[0].c='-';
	long long sum=0;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	} 
	long long val=0,l[30],r[30];
	for(int i=1;i<=30;++i) 
	{
		l[i]=0;
		r[i]=0;
	}
	bool flag=true;
	for(int i=1;i<=n;++i)
	{
		if(flag)
		{
			if(val+s[i].a<sum/2)
			{
				l[ch(s[i].c)]+=s[i].a;
				val+=s[i].a; 
				if(sum/2==val) flag=false;
			}
			else
			{
				flag=false;
				if(sum%2==0)
				{
					l[ch(s[i].c)]+=sum/2-val;
					val+=s[i].a;
					r[ch(s[i].c)]+=val-sum/2;
				}
				else
				{
					l[ch(s[i].c)]+=sum/2-val;
					val+=s[i].a;
					r[ch(s[i].c)]+=val-sum/2-1;
				}
			}
		}
		else
		{
			val+=s[i].a;
			r[ch(s[i].c)]+=s[i].a;
		}	
	}
	long long ans=INT_MIN;
	for(int i=1;i<=26;++i)
	{
		for(int j=1;j<=26;++j)
		{
			if(i!=j) ans=max(ans,max(r[i]-l[i],l[i]-r[i]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
bu bu bu bu bu bu bu,wo wu yi shi fen nu de
zhe ge bi sai zhen shi nang de guo fen
zi fu chuan is like da gou fen
8(2)yan han pu de nv peng you shi 8(5)zhang shu ya
*/
