#include<bits/stdc++.h>
using namespace std;
long long L;

long long f(long long n)
{
	return L-n+1;
 } 


struct duan{
	long long ln;
	long long bn;
	long long en;
	string sp;
};
duan a[200000];

int main()
{
	freopen("sring.in","r",sdtin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i].ln>>a[i].sp;
	    for(int j=1;j<=a[i].ln;j++)
	    {
	    	s+=a[i].sp;
		}
	    
	}

	 L=s.size();
	long long ans=0;
	for(int long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[L-i+1])ans++;
		}	
		//cout<<s;
		cout<<ans;
		return 0;
}
