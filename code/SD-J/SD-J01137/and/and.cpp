#include <iostream>
#include <string>
using namespace std;
string tobin(unsigned long long a){
	int bin[40];
	int n=1;
	string s="";
	for(int i=0;i<=39;i++) bin[i]=0;
	while(a>0)
	{
		bin[n]=a%2;
		a/=2;
		n++;
	}
	for(int i=32;i>=1;i--){
		s+=bin[i]+'0';
	}
	return s;
}
unsigned long long toint(string s){
	unsigned long long a=0,b=1;
	for(int i=31;i>0;i--)
	{
		a+=((s[i]-'0')*b);
		b*=2;
	}
	return a;
}
bool better(unsigned long long n,string a,string b){
	if(n==min(a.size(),b.size())) return 0;
	if(a[n-1]==b[n-1]) return better(n+1,a,b);
	else return (a[n-1]>b[n-1]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	unsigned long long n,m,a;
	string s[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		s[i]=tobin(a);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(better(1,s[j],s[j+1])) swap(s[j],s[j+1]);
		}
	}
	for(int i=1;i<=n;i++) cout<<toint(s[i])<<endl;
	unsigned long long ans=0;
	for(int i=n;i>=n-m+1;i--) ans&=toint(s[i]);
	cout<<ans;
	return 0;
}
