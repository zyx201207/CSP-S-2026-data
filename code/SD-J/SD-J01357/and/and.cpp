#include<bits/stdc++.h>

using namespace std;
int n,m,a[200010],maxn,cnt,num,sum[200010],o[200010],y[200010];
string s[200010];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 30; j++){
			s[i][j] = '0';
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1){
			cnt = a[i];
		}
		cnt = cnt & a[i];
		maxn = max(maxn,a[i]);
	}
	sort(a + 1,a + n + 1,cmp);
	if(m == n){
		cout << cnt << endl;
		return 0;
	}
	if(m == 1){
		cout << maxn << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int x = a[i],u = 0;
		while(x > 0){
			u++;
			x /= 2;
		}
		y[i] = u;
		x = a[i];
		while(u > 0){
			if(x >= pow(2,u - 1)){
				x -= pow(2,u - 1);
				s[i][u] = '1';
			}
			u--;
		}
	}
	for(int i = 30; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			if(o[j] == 1){
				break;
			}
			if(s[j][i] == '1'){
				sum[i]++;
			}else{
				if(sum[i] >= m && y[j] != 0){
					o[j] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= 30; i++){
		if(sum[i] >= m){
			num += pow(2,i - 1); 
		}
	}
	cout << num << endl;
	return 0;
}
