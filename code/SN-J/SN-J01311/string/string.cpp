#include<bits/stdc++.h>
#define lli long long
#define pi pair<lli,char>
using namespace std;
pi str[100005],str2[100005];
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x; 
		char ch;
		cin>>x>>ch;
		str[i]={x,ch};
		m+=x;
	}
	lli l1=m/2,tmp=0,tn=0;
	bool f=false;
	for(int i=1;i<=n;i++)
	{
		tmp+=str[i].first;
		if(tmp==12)
		{
			tn=i;
			break;
		}
	}
	int j=n;
	lli ans;
	if(f)
	{
		for(int i=1;i>=tn;i--)
		{
			if(i==tn)
			{
				if(tmp-12==0) break;
				if(n|1) str2[n-i+1]={tmp-l1-1,str[i].second};
				else str2[n-i+1]={tmp-l1,str[i].second};
			}
			else
			{
				str2[n-i+1]={str[i].first,str2[i].second};
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		
	}
	str[tn]={l1-(tmp-str(tn).first),str[tn].second};
	int len=0,lenth=0;
	for(int i=1,j=n;i<=tn && j<=tn-tmp;)
	{
		len=str[i].first,lenth=str[j];
		int len=str[i].first,lenth=str[j];
		while(len>0)
		{
			if(str[i].second!=str2[j].second) ans+=(len>=lenth ?lenth:len);
			if(lenth-len<=0) j++;
			len-=lenth;
		}
	}
	cout<<ans;
	return 0;
}
