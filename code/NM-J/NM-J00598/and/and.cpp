#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
	string a[2000010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	string s2,s;
    	cin>>x;
    	while(x!=0)
    	{
    		string s;
    		int y=x%2;
    		cout<<y;
			x=x/2;
			s+=char(y); 
		}
		for(int j=s.size()-1;j>=0;j--)
		{
			s2+=s[j];
		}
		a[i]=s2;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]; 
	}
    return 0;
}
	
