#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=0,x[1000005],num=0,sum=0;
int tong[1000005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a;
		cin>>x[i]>>a;
		if(a=='a') tong[1]++;
		if(a=='b') tong[2]++;
		if(a=='c') tong[3]++;
		if(a=='d') tong[4]++;
		if(a=='e') tong[5]++;
		if(a=='f') tong[6]++;
		if(a=='g') tong[7]++;
		if(a=='h') tong[8]++;
		if(a=='i') tong[9]++;
		if(a=='j') tong[10]++;
		if(a=='k') tong[12]++;
		if(a=='l') tong[12]++;
		if(a=='m') tong[13]++;
		if(a=='n') tong[14]++;
		if(a=='o') tong[15]++;
		if(a=='p') tong[16]++;
		if(a=='q') tong[17]++;
		if(a=='r') tong[18]++;
		if(a=='s') tong[19]++;
		if(a=='t') tong[20]++;
		if(a=='u') tong[21]++;
		if(a=='v') tong[22]++;
		if(a=='w') tong[23]++;
		if(a=='x') tong[24]++;
		if(a=='y') tong[25]++;
		if(a=='z') tong[26]++;
		for(int j=1;j<=x[i];j++) s=s+a;
		num++;
	}
	if(n==2)
	{
		if(x[1]==x[2])
		{
			cout<<x[1];
			return 0;
		}
		cout<<max(x[1],x[2]-min(x[1],x[2]));
		return 0;
	}
	for(int i=1;i<=26;i++)
	{
		if(tong[i]==num)
		{
			cout<<0;
			return 0;
		}
	}
	string ss;
	for(int i=s.size()-1;i>=0;i--) ss=ss+s[i];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=ss[s.size()-i])
		{
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}
/*3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
