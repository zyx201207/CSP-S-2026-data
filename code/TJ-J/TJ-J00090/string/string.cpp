#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int k;
		char c;
		cin>>k>>c;
		while(k--){
			s+=c;
		}
	}
	int l=0,r=s.size()-1,ans=0;
	while(l<r){
		if(s[l]!=s[r])
			ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
