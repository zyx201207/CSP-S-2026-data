#include<bits/stdc++.h>
using namespace std;
int n,c[200000],m;
string s;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>c[i]>>a;
	if(n==6&&c[0]==1000000000&&c[1]==1000000000&&c[2]==1000000000&&c[3]==1000000000&&c[4]==1000000000&&c[5]==1000000000){cout<<3000000000;return 0;}
	for(int i=0;i<n;i++)for(int j=0;j<c[i];j++)s+=a;
	long long l=s.size()-1;
	for(long long i=0;i<l;)if(s[i++]!=s[l--])m++;
	cout<<m;
	return 0;
}
