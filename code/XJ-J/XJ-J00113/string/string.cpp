#include <bits/stdc++.h>
using namespace std;
int n,ans;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;int k,len = 0;char c;
	a = " ";
	for(int i = 1;i <= n;i++){
		cin >> k >> c;len += k;
		while(k--){
			a+=c;
		}
	}
	for(int i = 1;i <= len/2;i++){
		if(a[i] != a[len+1-i]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
} 

