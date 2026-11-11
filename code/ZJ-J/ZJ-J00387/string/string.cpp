#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;
		char c;
		cin>>l>>c;
		for(int j=1;j<=l;j++){
			s+=c;
		}
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}


