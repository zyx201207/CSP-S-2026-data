#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
char s1[20000][10000]={0},s2[20000][10000]={0};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int c;
		cin>>a[i];
		cin>>c;
		for(int j=0;j<a[i];j++)
		{
			s1[i][j]=c;
		}
	}
	int ans=0;
	for(int i=n-1;i>=0;i++)
	{
		for(int j=a[i]-1;j>=0;j++)
		{
			s2[i][j]=s1[i][j];
			if(s2[i][j]!=s1[i][j])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
