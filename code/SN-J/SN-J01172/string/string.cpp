#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin >> n;
	while(n--){
		int a;
		char ch;
		cin >> a >> ch;
		for(int i=0;i<a;i++){
			s+=ch;
		}
	}
	long long l=0,r=s.size()-1,ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
