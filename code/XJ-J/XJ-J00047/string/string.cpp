#include<bits/stdc++.h>
using namespace std;
long long n,h[2020010],ans;
string m,l[2000220];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> h[i];
		cin >> l[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long  j=1;j<=h[i];j++){
			m+=l[i];
		}
	}
	for(long long i=0;i<(m.size())/2;i++){
		if(m[i]!=m[m.size()-i-1]) ans++;
	}
	cout << ans;
	return 0;
}
