#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,a;
string s;
char c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int l=s.size(),cnt=0;
	for(int i=0;i<(l/2);i++){
		if(s[i]!=s[l+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

