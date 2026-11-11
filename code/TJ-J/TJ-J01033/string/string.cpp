#include<bits/stdc++.h>
using namespace std;
int n,a[100005],s = 0;
char b[100005];
string o;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	cin >> a[1] >> b[1];
	int p = a[1];
	for(int i=2;i<= n;i++){
		cin >> a[i] >> b[i];
		p = __gcd(a[i],p);
	}
	for(int i = 1;i <= n;i++){
		a[i]/=p;
		while(a[i]--){
			o += b[i];
		}
	}
	for(int i = 0;i < o.size()/2;i++){
		if(o[i] != o[o.size()-i-1]){
			s++;
		}
	}
	cout << s*p;
}
