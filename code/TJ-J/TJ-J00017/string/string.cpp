
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int x;
		string s1;
		cin>>x;
		cin>>s1;
		for(int j=0;j<=x-1;j++)
		{
			s+=s1;
		}
	}
//	if(s.size()-1%2!=0)
//	{
//		int m=s.size();
//		char c=s[m];
//		s+=c;
//	}
//	cout<<s;
//	string s1,s2;
//	int x=s.size()/2+1;
//	for(int i=0;i<=x;i++)
//	{
//		s1[i]+=s[i];
//	}
//	
//	for(int i=x;i<=s.size()-1;i++)
//	{
//		s2[i]+=s[i];
//	}
//	cout<<s1<<" "<<s2<<"\n";
//	
//	int l=0,r=x,cnt=0;
//	for(int i=0;i<=s.size()+1;i++)
//	{
//		if(s1[i]!=s2[s2.size()-i])
//		{
//			cnt++;
//		}
//		if(i==s2.size()-i)
//		{
//			break;
//		}
//	}
	string s2=s;
	int cnt=0;
	reverse(s.begin(),s.end());
	for(int i=1;i<=s.size()/2+1;i++)
	{
		if(s[i]!=s2[i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	//int x=
	//for(int i=0;i<=n;i++)
	//{
		
	//}
	return 0;
}//string.in
