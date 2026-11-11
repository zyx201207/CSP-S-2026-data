#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
bool flag=0;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin >> n >> m;
	for(long long i=0;i<n;i++) {
		cin >> a[i];
	}
	for(long long i=2;i<n;i++){
		if(a[i-2]-a[i-1]==a[i-1]-a[i]){
			flag=true;
		} else {
			flag=false;
		}
	}
	if(flag) cout << m/(a[1]-a[0]);
	return 0;
}
