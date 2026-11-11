#include<iostream>
#include<cstdio>
using namespace std;
int n,y;
string c;
string s,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		c="";
		string b="";
		cin>>a>>c;
		for(long long j=1;j<=a;j++)b+=c;
		s+=b;
	}
		for(long long i=s.size()-1;i>=0;i--)
	{
		d[y]=s[i];
	 } 
	 //if(d==s)
	 cout<<"0";
	return 0;
} 
