//许愿出大象兵
#include <bits/stdc++.h>
using namespace std;
int flag[3005];
int n, r;
int a[3500];
void sb(int p, int cur){
	for(int i = p; a[i]-a[p]>r; i++){
		p++;
	}
}

int main(){
	freopen("E:\\OI\\migrate.in","r",stdin);
	freopen("E:\\OI\\migrate.out","w",stdout);
	cin >> c >> q;
	while(q--){
		
		cin >> n >> r;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			
		}
		for(int i = 1; i <= n; i++){
			sb(i,0);
		}
		cout << ans << endl;
		ans = 0;
		cout << 1;
	}
	return 0;
} 
