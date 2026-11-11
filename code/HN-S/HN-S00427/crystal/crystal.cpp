#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	int a[1001]={ },cnt;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==i){
			cnt=n;
		}
		else if((a[i]+a[n])*n/2){
			cnt=ceil((int)n/2)+1;
		}
	}
	cout << cnt;
	return 0;
}

