#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char b[200010];
int s,t;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i] >> b[i];
	for(int i = 1;i <= n;++i) s += a[i];
	for(int i = 1;i <= n;++i) for(int j = 1;j <= a[i];++j) c = c + b[i];
	for(int i = 1;i <= s / 2;++i) if(c[i] != c[s - i + 1]) t++;
	cout << t;
	return 0;
}
