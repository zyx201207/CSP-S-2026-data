#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
string s[MAXN];
bool f(string s){
	string s2;
	int i2 = 0;
	for(int i = s.size();i > 0;i--){
		s2[i2] = s[i];
		i2++;
	}
	if(s == s2)return 1;
	else return 0;
}
int main(){
 	preopen("string.in","r",stdin);
	preopen("string.out","w",stdout);
	long long fr,w = 0;
	long long ans = 0 ; 
	cin>>fr;
	for(int i = 0;i < fr;i++){
		long long n;
		char ch;
		cin>>n>>ch;
		for(int j=0;j<n;j++){
			s[i] = ch;
			w++;
		}
	}
	long long v  = w/2,q = w; 
	if(w%2 == 0){
		for(long long i = 0 ;i < v-1 ;i ++){
			if(s[i]!=s[q])ans++;
			q--;
		}
		cout<<ans;
	}else{
		for(long long i = 0 ;i < v- 1 ;i ++){
			if(s[i]!=s[q])ans++;
			q--;
		}	
		cout<<ans;	
	}
	return 0;
} 
