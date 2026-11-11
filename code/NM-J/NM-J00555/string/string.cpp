#include<bits/stdc++.h> 
using namespace std;
int n,a,ans;
string s,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>s;
		for(int j=0;j<a;j++)
		{
			x+=s;
		}
		while(n-i>=n/2)
		{
			if(x[i]==x[n-i]){
				              i++;
				            }
			if(x[i]!=x[n-i]){
				              x[n-i]=x[i];
				              ans++;
				              i++;
			                }
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
