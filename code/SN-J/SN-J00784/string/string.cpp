//许喆涵 SN-J00784 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int sum, ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		char c;
		int x;
		cin >> x >> c;
		for(int i=1;i<=x;i++)
			s+=c;
		sum+=x;
	}
	for(int i=0;i<sum/2;i++){
		char a=s[i];
		char b=s[sum-i-1];
		if(a!=b)
			ans++;
	}
	cout << ans;
	return 0;
}
