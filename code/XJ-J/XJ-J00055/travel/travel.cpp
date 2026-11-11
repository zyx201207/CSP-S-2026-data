#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    long long c[17],s[90],n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++){
		
    	cin>>c[i]>>s[i];
    }
	}
	for(int i=1;i<=n;i++){
	
	if(c[i]==c[i+1]||c[i]==c[i-1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    if((s[i]-'A'||s[i]-'B'||s[i]-'C'||s[i]-'D'||s[i]-'F')==(s[i-1]-'A'||s[i-1]-'B'||s[i-1]-'C'||s[i-1]-'D'||s[i-1]-'F')||(s[i]-'A'||s[i]-'B'||s[i]-'C'||s[i]-'D'||s[i]-'F')==(s[i+1]-'A'||s[i+1]-'B'||s[i+1]-'C'||s[i+1]-'D'||s[i+1]-'F'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
	return 0;
}
