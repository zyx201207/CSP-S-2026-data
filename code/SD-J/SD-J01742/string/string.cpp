#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,zong=0,q=0;
	cin>>n;
	string s;
	while(n--){
		int x;
		char y;
		cin>>x>>y;
		zong+=x;
		while(x--) s+=y;
	}
	long long l=0,r=zong-1;
	while(l<=r){
		if(s[l]!=s[r]) q++;
		l++;
		r--;
	}
	cout<<q;
	return 0;
}

