#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[200005][32],fl;
int c[200005];
vector<int> v;
void f(int x){
	int l = 31;
	int t = a[x];
	while(t){
		b[x][l] = t % 2;
		t /= 2;
		l --;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		f(i);
	}
	for(int i = 1;i <= 31;i ++){
		for(int j = 1;j <= n;j ++){
			if(b[j][i] && b[j][0] == 0){
				c[i] ++;
			}
		}
		if(c[i] >= m){
			fl = 1;
			for(int j = 1;j <= n;j ++){
				if(b[j][i] == 0){
					b[j][0] = 1;
				}
			}
		}
	}
	if(fl == 0){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		if(b[i][0] == 0) v.push_back(i);
	}
	ans = a[v[0]];
	for(int i = 0;i < m;i ++) ans = ans & a[v[i]];
	cout << ans;
	return 0;
}
