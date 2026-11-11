#include <bits/stdc++.h>
using namespace std;
bool isHui(string s)
{
	string a;
	for(int i=s.size()-1;i>=0;i--)
	{
		a+=s[i];
	}
	return a==s;
}
//string cut(string s,int p)
//{
//	string a;
//	int l=s.size();
//	for(int i=0;i<=p && i<l;i++)
//	{
//		a+=s[i];
//	}
//	return s;
//}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin >>n;
	for(int i=0;i<n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		for(int k=0;k<a;k++)
			s+=c;
	}//ÊäÈë
	int len = s.size(),cnt=0;
	int l=len/2-1,r=len/2+(len%2==0?0:1);
	while(!(l==-1 ||r==len))
	{
		if(s[l]!=s[r]){
			cnt++;
		}
		l--,r++;
	}
	cout << cnt;
	return 0;
 } 
