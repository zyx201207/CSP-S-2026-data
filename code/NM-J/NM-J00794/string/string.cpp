#include<bits/stdc++.h> 
using namespace std;
int n,cnt,a,op,d;
string s;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	op=n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++)
		s+=b;
		}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[op]){
			cnt++;
		}
		op--;
	}
	cout<<cnt;
	return 0;
}
