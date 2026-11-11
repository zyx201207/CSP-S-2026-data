#include<bits/stdc++.h>
using namespace std;
int n,q1[200010],cnt;
char q2[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> q1[i] >> q2[i];
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= q1[i]; j ++){
			s += q2[i];
		}
	}
	int l = 0,r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]){
			cnt ++;	
		}
		l ++,r --;
	}
	cout << cnt;
	return 0;
}
