#include <bits/stdc++.h>
using namespace std;
string s1,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long num;
		char wer;
		cin>>num>>wer;
		while(num>0){
			s+=wer;
			num--;
		}
	}
	for(long long i=0;i<s.size();i++){ 
		s1[i]=s[s.size()-i-1];
	}
	long long len=s.size();
	long long cnt=0;
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s1[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
