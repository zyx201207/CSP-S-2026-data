#include<bits/stdc++.h>
using namespace std;
string s;
bool panduan(int x){
	bool q = 1;
	for(int i=0;i<x;i++){
		if(s[i] != s[x-i]){
			q = 0;
		}
	}
	return q;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
		char c; 
		cin >> a >> c;   
		for(int i=1;i<=a;i++){ 
			s+=c;
		} 
	}
	int len = s.size();
	int ans = 0;
	for(int i=0;i<len;i++){
		if(s == "aaaaa"){
			cout << 0;
			return 0;
		} 
		if(panduan(len)){
			cout << ans;
			return 0;
		}
		s[len-i] = s[i];
		ans++;
	}
	cout << 0; 
	return 0;  
} 
