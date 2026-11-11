#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,len,q,r;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>x;
		r+=len;
		for(int k=1;k<=len;k++){
			s+=x; 
		}
	} 
	long long l=0;
	while(l<r){
		if(s[l]!=s[r]){
			q++;
		}
		l++;
		r--;
	}
	cout<<q;
	return 0;
}
