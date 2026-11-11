#include<bits/stdc++.h>

using namespace std;

unsigned long long n,a,ans,sum;
string s,c;
unsigned long long l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(unsigned long long i = 1; i <= n;i++){
		cin >> a >> c;
		sum += a;
		for(unsigned long long j = 1;j <= a;j++){
			s += c;
		}
	}
	sum--;
	if(sum % 2 == 1){
		l = sum / 2;
		r = (1 + sum) / 2;
	}
	else{
		l = sum / 2 - 1;
		r = sum / 2 + 1;
	}
	ans = 0;
	for(;l >= 1,r <= sum;l--,r++){
		if(s[r] != s[l]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
