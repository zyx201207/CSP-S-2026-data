#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
char c[N];
typedef long long ll;



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin.tie(0);
	
	ll n;
	cin >> n;
	string s;
	ll cnt = 0;
	for(ll i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	string str1,str2;
	ll ans = 0;
	ll c1 = 1,c2 = 1,n1=0,n2=0,n3=0,n4=0,num;
	n1 += a[c1];
	n2 += a[n -  c2 + 1];
	while(2 * n3 < cnt && 2 * n4 < cnt){
		num = min(n1,n2) - max(n3,n4);
		if(c[c1] != c[n - c2 + 1]){
			ans += num;
			//cout << ans << ' ' << num  << endl;
		}
		if(n1 > n2){
			c2 ++;
			n4 = n2;
			n2 += a[n - c2 + 1];
		}
		else if(n1 < n2){
			c1 ++;
			n3 = n1;
			n1 += a[c1];
		}
		else if(n1 == n2){
			c1++;
			c2++;
			n4 = n2;
			n3 = n1;
			n1 += a[c1];
			n2 += a[n - c2 + 1];
		}
	}
	cout << ans;
	return 0;
}


/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b



*/
