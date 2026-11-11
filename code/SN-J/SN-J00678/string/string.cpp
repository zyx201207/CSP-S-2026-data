//guocaocheng aizhizhongxue SN-J00678
#include<bits/stdc++.h>
using namespace std;
struct f{
	int m;
	char r;
}a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].m>>a[i].r;
		for(int j=1;j<=a[i].m;j++)
		{
			s=s+a[i].r;
		}	
	}
	bool f=1,t=1;
	int l=0,r=n-1;
	while(l<=r)
	{
		if(s[l]!=s[r]){
			f=0;
		}
		l++;
		r--;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	if(s.size()%2==1)
	{
		int k=s.size()-1;
		r=n-1;
		f=0,t=0;
		for(int i=0;i<n;i++)
		{
			if(i==k/2)
			{
				
				t=1;
				continue;		
			}
			if(s[i]==s[r]&&t==0)
			{
				k-=2;	
			}
			else if(s[i]==s[i+1]&&f==0)
			{
				k-=2;
				f=1;	
			}
			else if(s[i]==s[i+1]&&s[i]==s[r]&&t==0&&f==0)
			{
				k-=3;
				f=1;	
			}
			else if(s[i]==s[i+1]&&f==1)
			{
				k-=1;	
			}
			else if(s[i]==s[i+1]&&s[i]==s[r]&&t==0&&f==1)
			{
				k-=2;	
			}
			r--;
		}
		cout<<k;
		return 0;
	}
	if(s.size()%2==0)
	{
		int k=s.size()-1;
		r=n-1;
		f=0,t=0;
		for(int i=0;i<n;i++)
		{
			if(i==k/2)
			{
				
				t=1;
						
			}
			if(s[i]==s[r]&&t==0)
			{
				k-=2;	
			}
			else if(s[i]==s[i+1]&&f==0)
			{
				k-=2;
				f=1;	
			}
			else if(s[i]==s[i+1]&&s[i]==s[r]&&t==0&&f==0)
			{
				k-=3;
				f=1;	
			}
			else if(s[i]==s[i+1]&&f==1)
			{
				k-=1;	
			}
			else if(s[i]==s[i+1]&&s[i]==s[r]&&t==0&&f==1)
			{
				k-=2;	
			}
			r--;
		}
		cout<<k;
	}
	return 0;
}
