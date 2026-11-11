#include <bits/stdc++.h>
using namespace std;
bool hwc(string st)
{
	for(int i=0;i<st.size()/2;i++)
	{
		if(st[i]!=st[st.size()-i-1]) return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0;
    string c;
    string s="";
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long i=1;i<=a;i++) 
		{
		    s+=c;
		}
	}
	if(hwc(s))
	{
		cout<<0;
		return 0;
	}
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			s[s.size()-i-100]=s[i];
			sum++;
		}
		if(hwc(s))
		{
			cout<<sum;
			break;
		}
	}
	return 0;
}

