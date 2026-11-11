#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		s+=string(a,c);
	}
	int m=0;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			m++;
		}
		l++,r--;
	}
	cout<<m<<endl;
	return 0;
}