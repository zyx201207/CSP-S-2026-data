#include <bits/stdc++.h>
using namespace std;
string s,b[10000]; 
int a[10000],n,sum=0; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=a[i];i++)
		{
			s=b[i]+'0';
		 } 
	 }
	 for(int i=1;i<=s.length();i++)
	 {
	 	if(s[1]=s[s.length()]-i)
	 	{
	 		sum+=0;
		 }
		 else
		 {
		 	sum++;
		 }
	 } 
	 cout<<sum;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
