#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a,x=0;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a;
		if(a>x){
			x=a;
		}
	}
	if(m==1){
		cout << x;
		return 0;
	}
	return 0;
}
