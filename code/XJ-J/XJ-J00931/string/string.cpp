#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,a,l,r,k,t;
string c,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.cout","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	t=s.size();
     for(i=0;i<t;i++)
     {
     	if(s[i]!=s[t-i-1])
     	{
     		s[t-i-1]=s[i];
     		k++;
		 }
	 }
	 	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}