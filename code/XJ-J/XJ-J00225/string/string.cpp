#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int N=2e5+10;
LL n,cnt=0;
int a[N];
string s;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int len=s.size();
		for(int j=len-1;j<len-1+a[i];j++) s+=b[i];
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]) cnt++;
//		cout<<s[i]<<' '<<s[len-i-1]<<"\n";
	}
	cout<<cnt;
	return 0;
}
//a  a  a  a  a 
//0  1  2  3  4 
