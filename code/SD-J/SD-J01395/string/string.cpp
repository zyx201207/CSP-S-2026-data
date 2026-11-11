#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	long long T;
	cin>>T;
	while(T--){
		long long as;
		char sp;
		cin>>as>>sp;
		for(long long i=0;i<as;i++){
			s+=sp;
		}
	}
	long long n=s.size();
	for(long long i=0;i<n/2;i++){
		if(s[i]!=s[n-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

