#include<bits/stdc++.h>
using namespace std;
int n;
int m[200005];
long long sum,cnt;
int main(){
	ios::sync_with_stdio(0);
	cin&&cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	while(n--){
		int m;
		char c;
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			s+=c;
		}
	}
	for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--){
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	return 0;
}

