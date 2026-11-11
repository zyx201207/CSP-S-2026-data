#include<bits/stdc++.h>
using namespace std;
int n; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long int s[200100];
	char c[200100];
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>c[i];
	}
	int l=0,r=n-1;
	long long int sum=0;
	while(l<r)
	{
		if(c[l]!=c[r])//如果不同 
		{
			if(s[l]<s[r])
			{
				sum+=s[l];
				s[r]-=s[l];
				l++;
			}//修改前段 
			else if(s[l]>s[r])
			{
				sum+=s[r];
				s[l]-=s[r];
				r--;
			}//修改后端 
			else
			{
				sum+=s[r];
				r--;
				l++;
			}
			continue;
		}
		else
		{
			if(s[l]<s[r])
			{
				s[r]-=s[l];
				l++;
			}
			else if(s[l]>s[r])
			{
				s[l]-=s[r];
				r--;
			}
			else
			{
				r--;
				l++;
			}
			continue;
		}
	}
	cout<<sum;
	return 0;
}
