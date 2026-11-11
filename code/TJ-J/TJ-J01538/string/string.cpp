#include<bits/stdc++.h>
using namespace std;
struct seq{
	long long num;
	char c;
}s[200005];
long long pre[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].num>>s[i].c;
		sum+=s[i].num;
		pre[i]=pre[i-1]+s[i].num;
	}
	long long midpos=0;
	if(sum%2==1)
	{
		long long mid=sum/2+1;
		for(int i=1;i<=n;i++)
		{
			if(pre[i]>=mid)
			{
				midpos=i;
				s[i].num-=1;
				break;
			}
		}
	}
	long long dif=0;
	long long i=1,j=n;
	//long long mid=sum/2+1;
   // long long m=mid-pre[midpos-1];
    //if(m!=(s[midpos].num)/2)dif+=s[midpos].num-2*(m-1);
	while(i<j)
	{
		if(s[i].c!=s[j].c)
		{
			dif+=min(s[i].num,s[j].num);
			if(s[i].num>s[j].num)
			{
				s[i].num-=s[j].num;
				j--;
			}
			else if(s[j].num>s[i].num)
			{
				s[j].num-=s[i].num;
				i++;
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if(s[i].num>s[j].num)
			{
				s[i].num-=s[j].num;
				j--;
			}
			else if(s[j].num>s[i].num)
			{
				s[j].num-=s[i].num;
				i++;
			}
			else
			{
				i++;
				j--;
			}
	    }
    }
    //long long mid=sum/2+1;
    //long long m=mid-pre[midpos-1];
    //if(m!=(s[midpos]).num/2+1)dif+=abs(s[midpos].num-2*(m-1));
	cout<<dif;	
	return 0;
}
