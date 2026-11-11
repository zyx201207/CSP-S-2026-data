#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], pot, cnt[M];
bool b[M];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	stack<int> cd;
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			/*
			if(cd.empty()){
				pot = a[j];
			}
			*/
			cd.push(a[j]);
			if(b[a[j]] == 1){
				cd.pop();
				for(int k = j-1;a[k] != a[j];k--){
					cd.pop();
					b[k] = 0;
				}
			}
			else{
				b[a[j]] = 1;
			}
		}
		for(int j = 1;j <= m;j++){
			cnt[j] += b[j];
			//cout << cnt[j] <<' ';
			b[j] = 0;
		}
		//cout << '\n';
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] <<' ';
	}
	
	return 0;
}
