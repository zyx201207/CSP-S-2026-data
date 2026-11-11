#include<bits/stdc++.h>
using namespace std;
long long n;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long i=1;
	long long num=0;
	while(n--){
		long long a;
		char c;
		cin>>a;
		num+=a;
		cin>>c;
		for(;i<=num;i++){
			s[i]=c;
		}
	}
	int cnt=0;
	for(i=1;i<=num/2;i++){
		if(s[i]!=s[num+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
