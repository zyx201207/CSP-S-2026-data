#include <bits/stdc++.h>

using namespace std;
#define int long long
int m , n ,cnt;
string b , v[20000005];
signed main(){
	freopen("string.in" , "r" ,stdin);
	freopen("string.out" , "w" ,stdout);
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> n >> b;
		for(int j = 1;j <= n;j++){
			v[cnt+j]=b;
		}
		cnt+=n;
	}
	int ans=0;
	for(int i = 1;i <= cnt/2;i++){
		if(v[i]!=v[cnt-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
