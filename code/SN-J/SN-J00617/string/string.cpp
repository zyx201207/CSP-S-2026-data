#include<bits/stdc++.h>
using namespace std;
long long a,b,d,e,f,ans=0,n;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("streing.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
	    cin>>a>>c;
		string s1="";
		for(int i=1;i<=a;i++)
		{
			s1+=c;
		}
        s+=s1;
	}
	long long S=s.size();
	for(int i=0;i<S/2;i++)
	{
		if(s[i]!=s[S-1-i])
		{
			s[i]=s[S-i-1];
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

