#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(n[i]  <= 'a' and n[i] >= 'z'){
			cnt++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(n[i]  <= 'A' and n[i] >= 'Z'){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}