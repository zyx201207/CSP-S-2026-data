#define ll long long

#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 10;
ll a[mx];
char c[mx];
ll s[mx],f[mx];
char c2[mx];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll sum = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		sum += a[i];
	}
	int t = 0;
	for(int i = 1;i <= n;i++){
		char x = c[i];
		t++;
		s[t] = a[i];
		c2[t] = c[i];
		while(c[i + 1] == x){
			i++;
			s[t] += a[i];
		}
	}
	for(int i = t;i >= 1;i--)f[i] = f[i + 1] + s[i];
	ll ans = 0;
	ll head = 0,tail = 0;
	int tx = t + 1;
	bool flag = 0;
	for(int i = 1;i <= t;i++){
		head += s[i];
		char x = c2[i];
		while(tx > 1 && f[tx - 1] <= head){
			if(c2[tx - 1] != x)ans += f[tx - 1] - tail;
			tail = f[--tx];
		}
		if(c2[tx - 1] != x)ans += head - tail;
		tail = head;
	}
	ans = ans / 2;
	cout<<ans;
	return 0;
}
