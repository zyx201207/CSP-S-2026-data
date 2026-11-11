#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,x,len=-1,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		len+=x;
		for(int j=1;j<=x;j++){
			s=s+c;
		}
	}
	int l=0,r=len;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}

