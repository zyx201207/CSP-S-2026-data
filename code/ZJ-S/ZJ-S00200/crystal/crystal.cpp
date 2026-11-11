#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a[50010];
	long long dt[50010];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i < n;i++){
		int d[100010];
		int l = m;
		for(int j = 1;j < n;j++){
			d[j] = abs(a[i] - a[j+1]);
		}
		dt[i]++;
		int cnt = i;
		while(l > 0 && cnt > 0){
			if(l >= d[cnt] && cnt < n){
				dt[i]++;
				l -= d[cnt];
				cnt++;
			}
			else if(l < d[cnt] || cnt >= n-1){
				break;
			}
		}
	}
	sort(dt+1,dt+n,cmp);
	cout << dt[1];
	return 0;
}
