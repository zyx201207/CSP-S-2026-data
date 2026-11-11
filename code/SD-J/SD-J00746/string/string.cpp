#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int j=0;
	int a;
	char str;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>str;
		int t=j;
		for(;j<a+t;j++){
			s[j]=str;
		}
	}
	int len=j;
	int j2=len;
	for(int i=0;i<len/2;i++){
		j2--;
		if(s[i]!=s[j2]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
