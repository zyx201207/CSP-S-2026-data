#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		string t(a[i],c[i]);
		s+=t;
	}
	string s2=s;
	reverse(s2.begin(),s2.end());
	if(s2==s)
	{
		cout<<0;
		return 0;
	}
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])cnt1++;
		if(s.size()%2==1){
			if(i==s.size()-i-1)
			{
				break;
			}
		}
		else{
			if(i+1==s.size()-i-1)
				break;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]!=s[s.size()-i-1])cnt2++;
		if(i==s.size()-i-1)break;
	}
	cout<<min(cnt1,cnt2);
	return 0;
}