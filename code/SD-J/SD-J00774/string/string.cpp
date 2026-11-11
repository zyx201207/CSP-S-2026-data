#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	int l=0;
	int sum=0;
	int flag=1;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j=1;j<=x;j++){
			s[++l]=c;
		}
	}
	for(int i=1;i<=l/2+l%2;i++){
		if(s[i]!=s[l-i+1]){
			sum++;
			s[l-i+1]=s[i];
		}
	}
	cout << sum;
	return 0;
}
