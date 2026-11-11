#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
long long a[200005];
string s;
int main(){
	freopen("string in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>a[i]>>ch;
		for(int j=1;j<=a[i];j++){
			s+=ch;
		}
	}
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
