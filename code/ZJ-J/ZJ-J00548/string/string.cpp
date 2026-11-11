#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n;
 	cin>>n;
 	string s;
 	for(int i=1;i<=n;i++)
 	{
 		int a;
 		char c;
 		cin>>a>>c;
 		for(int j=1;j<=a;j++)
 		{
 			s+=c;
		 }
	 }
	 int l=0,r=s.size()-1,cnt=0;
	 while(l<r)
	 {
	 	if(s[l]==s[r])
	 	{
	 		cnt++;
		 }
		 l++;
		 r--;
	 }
	 cout<<s.size()/2-cnt;
    return 0;
}

