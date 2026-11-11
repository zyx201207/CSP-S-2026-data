#include<bits/stdc++.h>
using namespace std;
long long n,x,sum,cnt;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s=s+c;
		}
		sum+=x;
	}
	for(long long i=0;i<sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
