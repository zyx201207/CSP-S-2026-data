#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		int x = a[i],sum = 0;
		for(int j = 1;j <= n;j++){
			if(a[j] < x){
				sum += x-a[j];
			}
		}
		if(sum <= m){
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
