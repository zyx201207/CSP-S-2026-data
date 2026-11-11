#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	for(int i = 1;i <= m;i++){
		if(c - a > 0){
			a++;
		}
		if(c - b > 0){
			b++;
		}
	}
	
	if(a == c)ans++;
	if(b == c)ans++;
	if(c == c)ans++;
	if(d == c)ans++;
	if(e == c)ans++;
	cout << ans;
	return 0;
} 
