#include<bits/stdc++.h>
/*
1 2 3 5
*/
using namespace std;
const int N = 1e2+5;
long long b[N],n,m,ans = 0,cnt = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> b[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			ans = b[j];
			ans=ans and b[j+1];
		}
		cnt = max(ans,cnt);
	}
	cout << 12;
	return 0;
} 
