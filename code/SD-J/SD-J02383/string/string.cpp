#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	char s,r,t,w;
	long long a,e,q,b;
	cin>>b;
	for(int i = 0;i<b;i++){
		cin>>a>>r;
		e = e+a;
		for(int j = 0;j<a;j++){
			s = s+r;
		}
	}
	for(char c : s){
		t = t+c;
	}
	for(int i=e/2;i>=0;i--){
		w = w+s[i];
	}
	for(int i=e/2;i<=e;i++){
		for(char c:w){
			if(c!=s[i]){
				q++;
			}
		}
	}
	cout<<q;
	return 0£» 
}
