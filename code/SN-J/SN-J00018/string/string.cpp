#include<bits/stdc++.h>
using namespace std;
int n;
long long x,sum;
char u;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> x;
		cin >> u;
		for(long long i = 1;i <= x;i++){
			s += u;
		}
	}
	long long l = 0,r = s.size() - 1;
	while(l <= r){
		if(s[l] != s[r]) sum++;
		l++;
		r--;
	}
	cout << sum;
	return 0;
}

