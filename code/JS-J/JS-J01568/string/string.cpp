#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
int ans;
bool isss(string s1)
{
    string t=s1;
    string s2="";
    while(s1!="")
    {
	    int ss=s1.size()-1;
	    s2+=s1[ss];
	    s1.erase(ss,ss+1);
	}
	if(s2==t)
	    return true;
	else
	    return false;	
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		int a;
		char b;
	    cin>>a>>b;
	    for(int i=1;i<=a;i++)
	        s+=b;	
	}
	if(isss(s))
	{
	    cout<<'0'<<'\n';
	    return 0;
	}
	else
	{
		int l;
		l=s.size()/2-1;
		for(int i=0;i<=l;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				ans++;
			}
		}	 
	}
	cout<<ans;
	
    
   
	
    return 0;	
}

