#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	long long len=s.size();
	long long kqdsh=0;
	if(len%2==0){
		for(long long i=0,j=len-1;i<len/2&&j>=len/2;i++,j--){
			if(s[i]!=s[j]) kqdsh++;
		}
	}
	else{
		for(long long i=len/2,j=len/2;i>=0&&j<len;i--,j++){
			if(s[i]!=s[j]) kqdsh++;
		}
	}
	cout<<kqdsh;
	return 0;
}