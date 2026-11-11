//666，样例3给电脑卡死机了 
#include<bits/stdc++.h>
using namespace std;
long long n,mid,cnt,sum; 
char a;
string s; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt>>a;
		sum+=cnt;
		while(cnt>0)
		{
			s+=a;
			cnt--;
		}
	}
	//特判~~~~~~qwq 
	if(n<=1)
	{
		cout<<0<<endl;
		return 0;
	}

	int l=0,r=sum-1;
	
	if(sum%2==0)
	{
		mid=sum/2-1;
	}
	else
	{
		mid=sum/2;
	}
	for(int i=0;i<=mid;i++)
	{
		
		if(int(s[l]) != int(s[r]))
		{
			ans++;
			s[r]=s[l];
		}
		l++;
		r--;
	}
	
	cout<<ans<<endl;

    return 0;
    
}
