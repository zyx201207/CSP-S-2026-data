#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long int n;
long long int a[100005];
char ch[100005];
string s;
string s1;
long long int ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>ch[i];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=a[i];j++){
	  	s+=ch[i];
	}
	long long int len=s.size();
	for(int i=0;i<len;i++){
		s1+=s[len-i-1];
	} 
	if(s==s1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s[i]!=s1[i])
		  ans++;
	}
	cout<<ans/2;
	
	return 0;
}
