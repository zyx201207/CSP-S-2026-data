#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
typedef long long ll;
int a[N];
int cnt[N];
int b[N];
int tmp = 0;
//wo yao shang mi huo xing wei da shang
//67676767676767676767676767676767676767676767676767676767676767676767676767676767
//six seven
//ni hao
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int t = 1; t <= n; t++){
		for(int i = t; i <= n; i++){
			int u = a[i];
			bool ok = false;
			int pos = 0;
			if(tmp == 0)ok = false;
			else {
				for(int j = 1; j <= tmp; j++){
					if(b[j] == u){
						ok = true;
						pos = i;
					}
				}	
			}
			if(ok == false){
				tmp++;
				b[tmp] = u;
			}else {
				tmp = pos;
			}
		}
		for(int i = 1; i <= m; i++){
			bool ok = false;
			if(tmp == 0)ok = false;
			else {
				for(int j = 1; j <= tmp; j++){
					if(b[j] == i){
						ok = true;
						break;
					}
				}	
			}
			if(ok == true)cnt[i]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
