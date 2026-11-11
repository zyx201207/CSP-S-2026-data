//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#define int long long
#define pb push_back
using namespace std;

const int N = 3e5 + 5;
int a[N], sum[N];
vector <int> v;
bool f[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++) 
		cin >> a[i];
	
	int l = 0;	
	
	while(++ l <= n) {
		memset(f, 0, sizeof(f));
		v.clear();
		
		for(int i = l; i <= n; i ++) {
			v.pb(a[i]);
			
			if(!f[a[i]]) f[a[i]] = 1; 
			
			else {  
				bool flag = 0;
				
				for(auto x : v) {
					if(x == a[i] and !flag) {
						v.pop_back();
						flag = 1;
					} 
					else if(flag and x == a[i]) break;  
					else if(flag and x != a[i]) {
						v.pop_back();
						f[x] = 0;
					}
				}
			}
		}
		
		for(auto x : v) sum[x] ++; 
	}
	
	for(int i = 1; i <= m; i ++) 
		cout << sum[i] << " ";
	
	return 0;
} 






















