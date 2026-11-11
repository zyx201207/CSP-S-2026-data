#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		char c;cin >> c;
		len+=x;
		for(int j=1;j<=x;j++) s += c;
	}
	
	long long i=0,j=len-1,ans=0;
	while(i<j){
		if(s[i] != s[j]) ans++;
		i++,j--;
	}
	cout << ans;
	return 0;
}
