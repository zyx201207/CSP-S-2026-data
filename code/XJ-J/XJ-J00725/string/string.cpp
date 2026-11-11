#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
//不开long long 后悔100年！！！！！ 
long long a[N],half=0,tot=0,cnt=0;//a<=1e9
int n;//n<=2e5
char c[N];
long long de=1e9+10;
long long llmin(long long m1,long long m2)
{
	if(m1>m2)return m2;
	else return m1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		de=llmin(a[i],de);
	}
	de-=1;
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(a[i]-de);j++)
		{
			s+=c[i];
	 	} 
	}
	half=floor(s.size()/2);
	string sl,sr;
	if((int)s.size()%2==1)
	{
		int j=half-1;
		for(int i=0;i<half;i++)
		{
		 sl+=s[j];
		 j--;
	    }
  		for(int i=half+1;i<(int)s.size();i++)sr+=s[i];
	}
	else {
		int j=half-1;
		for(int i=0;i<half;i++)
		{
		 sl+=s[j];
		 j--;
	    }
  		for(int i=half;i<(int)s.size();i++)sr+=s[i];
	} 
	for(int i=0;i<(int)sr.size();i++)
	{
		if(sr[i]!=sl[i])cnt++;
		cnt+=cnt==0?0:de;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

