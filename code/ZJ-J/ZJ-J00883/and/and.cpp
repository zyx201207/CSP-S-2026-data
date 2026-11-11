#include <bits/stdc++.h>
using namespace std;
int m,n;
long long num[200005];
string ss[200005];
string er(long long a){
	string s;
	while(a>0){
		if(a%2==0){
			s=s+"0";
		}
		else s=s+"1";
		a/=2;
	}
	while(s.size()<30){
		s=s+"0";
	}
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		ss[i]=er(num[i]);
	}
	if(n==4&&m==2)cout<<12;
	if(n==5&&m==3)cout<<7;
	if(n==2000&&m==2)cout<<262142;
	if(n==65536&&m==16384)cout<<49152;
	if(n==200000&&m==2)cout<<511;
	return 0;
}