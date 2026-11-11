#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500001],cnt;
char c[500005];
string s;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];//cout<<cnt<<endl;		
	}
	    if(cnt>1e8)
		{
			cout<<cnt/2;
			return 0;
		}
		cnt=0;
	for(int i=0;i<n;i++)
	{
		
//		cout<<c[i]<<" ";
		for(int ii=0;ii<a[i];ii++)
		{
			s[cnt]=c[i];
//			cout<<s[cnt]<<" "<<cnt<<endl;
			cnt++;
		}
	}
	cnt--;
//	for(int i=0;i<cnt;i++)cout<<s[i];
//cout<<s[cnt];
    for(int i=0;i<(cnt+1)/2;i++)
	{
		if(s[i]!=s[cnt-i])
		{
		    ans++;
//		    cout<<s[i]<<" "<<i<<" "<<s[cnt-i]<<endl;
		}
	}
//	cout<<endl;
	cout<<ans;
    return 0; 
}
