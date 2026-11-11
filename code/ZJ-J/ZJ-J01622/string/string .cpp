#include <bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];
int main (){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	int L=1,R=n;
	long long cnt=0;
	while(L<R){
		int t=min(a[L],a[R]);
		if(c[L]!=c[R]){
			cnt+=t;
		}
		a[L]-=t;
		a[R]-=t;
		if(a[L]==0){
			L++;
		}
		if(a[R]==0){
			R--;
		}
	}
	cout << cnt;
}
