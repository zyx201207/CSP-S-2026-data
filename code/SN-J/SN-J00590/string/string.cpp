#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,cnt;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=0;i<a;i++){
			s+=b;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0; 
}
