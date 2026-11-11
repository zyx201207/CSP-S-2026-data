#include<bits/stdc++.h>
using namespace std;
char s[500000000];long long len,cnt;
int main(){
	ifstream ci("string.in");
	ofstream co("string.out");
	int n;
	ci>>n;
	for(int i=1;i<=n;i++){
		long long a;char c;
		ci>>a>>c;
		for(int j=len;j<len+a;j++)s[j]=c;
		len+=a;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	co<<cnt;
	return 0;
}
