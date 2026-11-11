#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
char ch;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>ch;
		for(int j=1;j<=k;j++){
			s+=ch;
		}
	}
	
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
}

	
