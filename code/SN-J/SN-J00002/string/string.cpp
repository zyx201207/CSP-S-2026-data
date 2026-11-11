#include <bits/stdc++.h> 
using namespace std;
int main{
freopen("train.in","r",stdin);
freopen("train.out","w",stdout);
string s[i]={};
int n;
cin>>n;
int ans;
cin>>ans;
for(int i=0;i<=n;i++)
{  if(s[i]==s[i-1])break;
	else if(s[i]!=s[i-1])
    { s[i]=s[i-1];
        abs++;
	   if(s[i]=s[i-1])break; 	
      else{
      	
      	ans++;
	  }	
}

cout<<ans;
return 0£» 
}
