#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k,l=0,r,num=0;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> k;
		cin >> c;
		r+=k;
		while(k--){
			s1+=c;
		}
		s+=s1;
		s1={};
	}
	int r1=r;
	for(;l<r1/2;l++){
		r=r1-l-1;
		if(s[l]!=s[r]) num++;
	}
	cout << num;
	return 0;
}
