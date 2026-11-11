#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	long long n,m;
	cin>>n;
	string s,x;
	for(long long i=0;i<n;i++){
		cin>>m>>x[i];
		for(long long j=0;j<m;j++){ 
			s += x[i];
		}
	}
	long long l = s.size();
	bool f = true;
	for(long long i=0;i<l;i++){
		if(s[i] == s[l-1-i]){
			f = true;
		}else{
			f = false;
			break;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	string v;
	if(f == false){
		for(long long i=0;i<l;i++){
			v += s[l-i-1];
		}
	}
	long long sum1 = 0,sum2 = 0;
	for(long long i = 0;i < l / 2;i++){
		if(v[i] != s[i]){
			sum1++;
		}
	}
	for(long long i = l;i > l / 2 - 1;i--){
		if(v[i] != s[i]){
			sum2++;
		}
	}
	if(sum1 > sum2){
		cout<<sum2;
	}else{
		cout<<sum1;
	}
	return 0;
} 

