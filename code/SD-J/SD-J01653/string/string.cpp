#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s=s+c;
		}
	}
	n=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			n++;
		}
	}
	cout<<n;
	return 0;
}
