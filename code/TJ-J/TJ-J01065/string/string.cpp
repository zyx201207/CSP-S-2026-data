#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long a;
	string s,b;
	while (n--){
		cin >> a >> b;
		for (long long i=0;i<a;i++){
			s+=b;
		}
	}
	string old=s;
	reverse(s.begin(),s.end());
	long long len=s.size();
	long long cnt=0;
	for (long long i=0;i<len/2;i++){
		if (old[i]!=s[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
