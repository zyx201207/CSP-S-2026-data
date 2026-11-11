#include <bits/stdc++.h>
using namespace std;
string s,sub1,sub2;
int n,ans;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int a;
		string c;
		cin >> a >> c;
		l += a;
		while(c.size() <= a){
			c = c + c;
		}
		string sc = c.substr(0,a);
		s = s + sc;
	}
	
	sub1 = s.substr(0,l / 2);
	sub2 = s.substr(l - l / 2,l / 2);
	for(long long i = 0;i <= l / 2;i++){
		if(sub1[i] != sub2[i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
