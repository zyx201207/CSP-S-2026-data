#include <bits/stdc++.h>
using namespace std; 
long long n,x;
char c;
string s;
int main()
{  
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   while(n--){
   cin>>x>>c;
   for(int i=1;i<=x;i++)s+=c;
   }
   s=" "+s;longv long ans=0;
   for(int i=1;i<=((int(s.size())-1)+1)/2;i++)
   {
	   if(s[i]!=s[int(s.size())-1+1-i])ans++;
   }
   cout<<ans;
   return 0;
}
