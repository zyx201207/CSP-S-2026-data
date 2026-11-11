#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , b[500005] , v[300005] , sum[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			v[j] = 0;
		}
		long long num = 0;
		for(int j = i;j <= n;j++){
			if(!v[a[j]]){
				b[++num] = a[j];
				v[a[j]] = num;
			}
			else{
				for(int k = v[a[j]] + 1;k <= num;k++){
					v[b[k]] = 0;
				}
				num = v[a[j]];
			}
		}
		for(int j = 1;j <= num;j++){
			sum[b[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
