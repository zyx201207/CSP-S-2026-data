#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,x,l = 0,sum =0,sum1 = 0;
	char a;
	string s;
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> x >> a;
		l += x;
		for(long long j = 1;j <= x;j++){
			s+=a;
		}
	}
	if(l %2 == 0){
		for(long long i = l/2;i < l;i++){
			if(s[i]!=s[i-l/2])sum++;
		}
	}
	else{
		for(long long i = l/2+1;i < l;i++){
			if(s[i]!=s[i-l/2-1])sum++;
		}
	}
	cout << min(sum,sum1);
	
	return 0;
}