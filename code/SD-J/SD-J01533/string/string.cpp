#include<bits/stdc++.h>
using namespace std;
long long n=0,number=0,mid=0,num[20005]={0},ans=0;
char word[20005],w;
bool flag=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>word[i];
		number+=num[i];
	}
	w=word[1];
	for(int i=2;i<=n;i++)
	{
		if(w!=word[i]) 
		{
			flag=0;
			break;
		}
	}
	if(flag) 
	{
		cout<<'0';
		return 0;
	}
	if(number%2==1) mid=number/2+1;
	else mid=number/2;
	int m=0;
	for(int i=1;i<=n;i++)
	{
		long long j;
		j+=num[i];
		if(j>=mid) 
		{
			m=i;
			break;
		}
	}
	long long k=0;
	long long a=1,b=n,c=0,choice=0;
	while(k<=mid)
	{
		if(choice==1) 
		{
			while(num[a]<c)
			{
				c-=num[a];
				k+=num[a];
				if(word[a]!=word[b])ans+=num[a];
				a++;
			}
			b--;
			num[a]-=c;
		}
		if(choice==2) 
		{
			while(num[b]<c)
			{
				c-=num[b];
				k+=num[b];
				if(word[a]!=word[b])ans+=num[b];
				b--;
			}
			a++;
			num[b]-=c;
		}
		k+=c;
		if(num[a]>num[b])
		{
			choice=1;
			k+=num[b];
			c=num[a]-num[b];
			if(word[a]!=word[b]) ans+=num[b];
			b--;
		}
		if(num[a]==num[b])
		{
			choice=0;
			k+=num[a];
			c=0;
			if(word[a]!=word[b]) ans+=num[b];
			b--;
			a++;
		}
		if(num[a]<num[b])
		{
			choice=2;
			k+=num[a];
			c=num[b]-num[a];
			if(word[a]!=word[b]) ans+=num[a];
			a++;
		}
		if(k>mid) ans-=k-mid;
	}
	cout<<ans;
	return 0;
}
