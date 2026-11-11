#include<bits/stdc++.h>
using namespace std;
int n , m;
long long int a[200005];
long long int b[200005][40];
long long int c[40];
long long int sum;
bool asdf[200005];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1; i <= n; i++){
		long long int k = a[i];
		long long int num = 0;
		while(k > 0){
			num++;
			b[i][num] = k % 2;
			k /= 2;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 35; j++){
			c[j] += b[i][j];
		}
	}
	int qwer = 0;
	for(int i = 1; i <= n; i++){
		asdf[i] = true;
	}
	long long int num = 0;
	for(int i = 35; i >= 1; i--){
		queue<long long int> qu;
		while(!qu.empty()){
			qu.pop();
		}
		if(c[i] >= m){
			for(int j = 1; j <= n; j++){
				if(b[j][i] == 1 && asdf[j]){
					qu.push(j);
				}
			}
			for(int j = 1; j <= 35; j++){
				c[j] = 0;
			}
			for(int j = 1; j <= n; j++){
				asdf[j] = false;
			}
			while(!qu.empty()){
				long long int k = qu.front();
				asdf[k] = true;
				for(int j = 1; j <= 35; j++){
					c[j] += b[k][j];
				}
				qu.pop();
			}
		}
	}
	long long int k = 1;
	for(int i = 1; i <= 35; i++){
		if(c[i] >= m){
			num = num + k;
		}
		k *= 2;
	}
	cout << num;
	return 0;
}
