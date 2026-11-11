#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,ch,cnt=0;
	string s="",s1;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>k>>s1;
		for(int j=1;j<=k;++j)
			s+=s1;
	}
	n=s.size();
	int l=0,r=n-1;
	while(l<r){
		if(s[l]!=s[r]) 
			cnt++;
			
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
