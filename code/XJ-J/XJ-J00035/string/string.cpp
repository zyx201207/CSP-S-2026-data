#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,tot,temp,tempr,lst;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char t;
		cin>>x>>t;
		for(int i=1;i<=x;i++){
			s+=t;
		}
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) tot++;
		l++,r--;
	}
	cout<<tot;
	return 0;
}
