#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 2e5 + 10;
ll n, m, a[maxn], maxx = -1, s[maxn], num[maxn];
bool flag = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		s[i] = s[i - 1] + a[i];
		if(i != 1 && i != 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			flag = 0;
	}
	if(flag){
		m /= (a[2] - a[1]);
		num[1] = 1;
		for(int i = 2;i <= 500000;i++)
			num[i] = num[i - 1] + i;
		for(int i = 1;i <= 500000;i++)
			if(num[i] > m){
				cout<<i<<"\n";
				return 0;
			}
				
	}
	sort(a + 1, a + n + 1);
	for(int i = 2;i <= n;i++){
		ll c = 0, pos = 1;
		for(int j = i;j >= 1;j--){
			c += a[i] - a[j];
			if(c > m) {pos = j + 1; break;}
		}
		maxx = max(maxx, i - pos + 1);
	}
	cout<<maxx<<"\n";
	return 0;
} 
//CCF = Chinese Can Fly!!! = CPL Can Fly!!!!!!!
