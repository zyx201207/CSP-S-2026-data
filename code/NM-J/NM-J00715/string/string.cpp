#include<bits/stdc++.h>
using namespace std;
string s,s_1,s_2;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
        long long qw;
		char er;
		cin>>qw>>er;
		ans+=qw;
		for(long long j=0;j<qw;j++){
			s+=er;
		}
	}
	cout<<ans;
	for(long long i=0;i<ans/2;i++){
		s_1+=s[i];
	}
	for(long long i=ans-1;i>=ans-ans/2;i--){
		s_2+=s[i];
	}
	cout<<s<<' ';
	cout<<s_1<<' '<<s_2<<endl;
	long long cnt=0;
	for(long long i=ans-1;i>=0;i--){
		if(s_1[i]!=s_2[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
