#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,js,ansa,num[N];
int flag;
/*struct node
{
	int num;
	char st;
}ve[N];*/
char st[N],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%s",&num[i],&s);
		st[i]=s;
	}
	int l=1,r=T;
	while(l<r)
	{
		if(num[l]==num[r]&&st[l]!=st[r])
		{
			ansa+=num[l];
			l++;
			r--;
			flag=1;
		}
		else if(num[l]!=num[r])
		{
			int jsa=0;
			while(jsa<num[r]&&l<r)
			{
				if(st[r]!=st[l]&&jsa<num[r]) ansa+=num[l];
				else if(st[l]!=st[r]) ansa+=(num[r]-num[l-1]);
				l++;
				jsa+=num[l];
			}
			if(jsa!=num[r]) num[l]-=(num[r]-num[l-1]);
			jsa=0;
			while(num[l]>num[r]&&jsa<num[l]&&l<r)
			{
				jsa+=num[r];
				if(st[l]!=st[r]&&jsa<num[l]) ansa+=num[r];
				else if(st[l]!=st[r]) ansa+=(num[l]-num[r-1]);
				r--;
			}
			if(jsa!=num[l]) num[r]-=(num[l]-num[r-1]);
		}
	}
	printf("%d",ansa);
	return 0;
} 
