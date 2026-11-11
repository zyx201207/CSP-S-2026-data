#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		
		long long n,d,cnt2=0;
		cin>>n>>d;
		long long a[n+5];
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int len=3;len<n;len++)
		{
			for(int i=1;(i+len)<=n;i++)
			{
				int start=i+len-3,end=i+len,cnt=0;
				if( abs(a[start]-a[start+1]) <=d )	
				{
					cnt++;
				}
				if( abs( a[end-1] - a[end] ) <=d )	
				{  
					cnt++;
				}
				if( abs( a[start] - a[end] ) <=d)
				{
					cnt++;
				}
				if(cnt==2)
				{
					cnt2++;	
				}
			}
		}
		cout<<cnt2<<endl;
	}
	return 0;
}
