#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int u[10005],v[10005];
bool flag = true;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n-1;i++){
			cin >> u[i] >> v[i];
			if(v[i] - u[i] > 1) flag = false;
		}
		if(flag) cout << 1 << endl;
		else cout << 2 << endl;
		flag = true;
	}
	return 0;
}
