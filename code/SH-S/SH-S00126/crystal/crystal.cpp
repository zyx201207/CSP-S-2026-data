#include<bits/stdc++.h>
using namespace std;
int n;
long long m,l,x,y;
int mx;
long long a[500010];
int b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		
	}
	sort(a + 1,a + n + 1);
	b[0] = 0;
	l = m;
	a[0] = 0;
	mx = 0;
	for(int i = 1;i <= n;i++){
		x = a[i] - a[i - 1];
		y = b[i - 1];
		while(l < y * x){
			
			l = l + (a[i - 1] - a[i - y]);
			y--;
		}
		l = l - x * y;
		b[i] = y + 1;
		mx = max(mx,b[i]);
	}
	cout << mx << "\n";
} 
