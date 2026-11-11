#include<bits/stdc++.h>
using namespace std;
int a[20005];
char c[20005];
long long zm[30];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]=='a')zm[1]+=a[i];
		if(c[i]=='b')zm[2]+=a[i];
		if(c[i]=='c')zm[3]+=a[i];
		if(c[i]=='d')zm[4]+=a[i];
		if(c[i]=='e')zm[5]+=a[i];
		if(c[i]=='f')zm[6]+=a[i];
		if(c[i]=='g')zm[7]+=a[i];
		if(c[i]=='h')zm[8]+=a[i];
		if(c[i]=='i')zm[9]+=a[i];
		if(c[i]=='j')zm[10]+=a[i];
		if(c[i]=='k')zm[11]+=a[i];
		if(c[i]=='l')zm[12]+=a[i];
		if(c[i]=='m')zm[13]+=a[i];
		if(c[i]=='n')zm[14]+=a[i];
		if(c[i]=='o')zm[15]+=a[i];
		if(c[i]=='p')zm[16]+=a[i];
		if(c[i]=='q')zm[17]+=a[i];
		if(c[i]=='r')zm[18]+=a[i];
		if(c[i]=='s')zm[19]+=a[i];
		if(c[i]=='t')zm[20]+=a[i];
		if(c[i]=='u')zm[21]+=a[i];
		if(c[i]=='v')zm[22]+=a[i];
		if(c[i]=='w')zm[23]+=a[i];
		if(c[i]=='x')zm[24]+=a[i];
		if(c[i]=='y')zm[25]+=a[i];
		if(c[i]=='z')zm[26]+=a[i];
	}
	sort(zm+1,zm+26+1);
	if(n==1) cout<<0;
	else if(n==2)
	{
		if(c[1]==c[2])cout<<0;
		else cout<<min(a[1],a[2]);
	}
	else
	{
		cout<<n-zm[26];
	}
	return 0;
}
