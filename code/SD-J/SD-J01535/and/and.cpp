#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m,compare[35],maxx = -1,t;
char c[200005][35],cha[200005][35],chr[35];
void two(int i,int j){
	int s = 0;
	while (i >= 0){
		s++;
		c[j][s] = char(i % 2 + '0');
		i /= 2;
	}
	compare[s]++;
	maxx = max(maxx,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		two(a[i],i);
	}
	for (int i = maxx;i >= 1;i--){
		if (compare[i] >= m){
			t = i;
			break;
		}
	}
	int l = 0;
	for (int i = 1;i <= n;i++){
		if (c[i][t] == '1'){
			l++;
			for (int j = 1;j <= t;j++){
				cha[l][j] = c[i][j];
			}
		}
	}
	chr[1] = '1';
	int lenth = 0;
	int r = 0,d = 1;
	while (--t){
		d++;
		if (l == m){
			bool flag = false;
			for (int i = 1;i <= m;i++){
				if (cha[i][t] == '0'){
					chr[d] = '0';
					flag = true;
					break;
				}
			}
			if (flag){
				continue;
			}
		}
		for (int i = 1;i <= l;i++){
			if (cha[i][t] == '1'){
				lenth++;
			}
		}
		if (lenth >= m){
			for (int i = 1;i <= l;i++){
				if (cha[i][t] == '1'){
					r++;
					for (int j = 1;j <= t;j++){
						cha[r][j] = cha[i][j]; 
					}
				}
			}
			l = lenth;
			chr[d] = '1';
		}else{
			chr[d] = '0';
		}
	}
	long long sum = 0,k = 1;
	for (int i = 1;i <= d;i++){
		sum += (chr[i] - '0') * k;
		k *= 2;
	}
	cout << sum;
	return 0;
}
