#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[2000000];
	int n;
	long long a,l=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=l;j<=l+a;j++){
			s[j]=c;
		}
		l+=a;
	}
	int num=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}