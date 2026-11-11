#include<bits/stdc++.h> 
using namespace std;
string s;
long long n,cnt;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
    	string s1;
    	long long m;
    	cin>>m>>s1;
    	for(long long j=1;j<=m;j++)
		    s+=s1; 
    	
	} 
	long long len=s.size()-1; 
	for(long long i=0;i<=(len+1)/2;i++) 
	{
		 if(s[i]!=s[len-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
