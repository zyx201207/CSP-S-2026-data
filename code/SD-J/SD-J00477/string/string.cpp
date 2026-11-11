#include<bits/stdc++.h>
using namespace std;
char w;
string s;
long long n,q,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> q;
		cin >> w;
		for(int j=0;j<q;j++){
			s=s+w;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
