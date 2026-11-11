#include<bits/stdc++.h>
using namespace std;
string s[10000010];
int main(){
	long long n,x=0;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1+x;j<=a;j++){
			s[j]=c;
			cnt++;
		}
		long long x=a;
	}
	long long sum=0;
	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i]){
			sum++;
		}
	}
    cout<<sum;
	return 0;
}
