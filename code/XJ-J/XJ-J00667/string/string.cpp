#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l;
	string s="",t;
	char a;
	cin>>n;
	while(n--)
	{
		cin>>l;
		cin>>a;
		while(l--)
		{
			s+=a;
		}
	}
	//cout<<s<<endl;
	int len=s.size();
	
	for(int i=len-1;i>=0;i--)
	{
		t+=s[i];
	}
	//cout<<t<<endl;
	int f=0,cnt=0;
	while(f<len/2)
	{
		if(s[f]!=t[f])
			cnt++;
		f++;
	}
	cout<<cnt;
	return 0;
}
//int to_shu(string x)
//{
//	int len=x.size()-1,a=0;
//	for(int i=0;i<=len;i++)
//	{
//		a=a*10+(x[i]-'0');
//		cout<<x[i];
//	}
//	return a;
//}
//int n,tshu=0,shu;
//string tzi,zi;
//string ss[200005];
//int main()
//{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	cin>>n;
//	int j=1;
//	int flag=0;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>shu>>zi;
//		if(tzi==zi and flag==0)
//		{
//			shu+=tshu;
//		}
//		else
//		{
//			ss[j-1]=to_string(tshu)+tzi;
//			cout<<ss[j-1]<<endl;
//		}
//		if(i==n)
//			ss[j]=to_string(tshu)+tzi;
//		cout<<to_shu(ss[j-1]);
//		tshu=shu;tzi=zi;
//		
//	}
//	return 0;
//}