#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n;
string s;
int b;
string c;
string a;
string f;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    if(n==1)
    {
    	cout<<"0";
	}
    for(int i=0;i<n;i++)
    {
        cin>>b>>c;
		while(b--)
		{
			s+=c;
		}	
	}
	for(int i=0;i<n;i++)
    {
        cout<<s[i];
	}
	int len=s.size();
	int ans=len/2;
	for(int i=0;i<=ans;i++)
	{
		a[i]=s[i];
	}
	int res=-1;
	for(int i=len-1;i>=ans;i--)
	{
		
		f[++res]=s[i];
	}
	int k=0;
	for(int i=0;i<=res;i++)
	{
		if(f[i]!=a[i])
		{
			k++;
		}
	}
	cout<<k;
	return 0;
}

