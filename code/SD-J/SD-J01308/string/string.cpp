#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=s+' ';
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s=s+y;
		}
	}
	int l=s.size()-1;
	if(l%2!=0){
		int dc=(l+1)/2;
		for(int i=1;i<dc;i++){
			if(s[dc-i+dc]!=s[i]){
				ans++;
			}
		}
	}else{
		int dc=l/2;
		for(int i=1;i<=dc;i++){
			if(s[dc-i+dc+1]!=s[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
