#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a;
	char c;
} a[2000005];
int sum[2000005];
int n;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%lld %c", &a[i].a, &a[i].c);
		sum[i] = sum[i-1] + a[i].a;
		// 3 aabbc
		// i: sum[i-1]+1 ~ sum[i]
		
	}
	
	if(1){
		string  str;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= a[i].a; j++){
				str += a[i].c;
			}
		}
		string s1 = str.substr(0, (int)floor(1.0*str.length()/2));
		string s2 = str.substr((int)floor(1.0*str.length()/2));
		reverse(s2.begin(), s2.end());
		int cnt = 0;
		for(int i = 0; i < s1.length(); i++){
			if(s1[i] != s2[i]) cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	// aaaaammmmbbb
	// 123456789 10 11 12
	int l = 1, r = n, lc = 1, rc = sum[n], sum = 0;
	if(a[l].a > a[r].a){
		if(a[l].c != a[r].c) sum += a[r].a;
		lc -= a[r].a;                                                        
		rc -= a[r].a;                          
	}                                      
	
	return 0;
}
