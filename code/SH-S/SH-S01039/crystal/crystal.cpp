#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int max = -1;
	for(int i=1;i<=n;i++){
		bool finish = 0;
		int cnt = 0,sum = 0;
		for(int j=1;j<=n;j++){
			if(j == i){
				continue;
			}
			if(a[i] < a[j]){
				break;
			}
			sum += a[i] - a[j];
			if(sum < m){
				cnt++;
			}else if(sum == m){
				cnt++;
			}else{
				finish = 1;
			}
			if(finish){
				break;
			}
		}
		cnt++;
		if(max < cnt){
			max = cnt;
		}
	}
	cout << max;
	return 0;
}
