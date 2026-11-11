#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ans=0;
	long long sum=0,min=1000000000001,max=-1000000000001;
    cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		if(a[i] > max) max = a[i];
		if(a[i] < min) min = a[i];
	}
	int divlow = 0;
	for(int i = 0;i < n;i++){
		divlow += (max - a[i]);
	}
	if(divlow <= m){
		cout << n;
		return 0;
	}
	sort(a,a+n);
	long long nowans = 0;
	for(int i = max;i >= min;i--){
		for(int j = 0;j < n;j++){
			if(a[j] > i) continue;
			if(a[j] == i) nowans++;
			if(a[j] < i){
				if ((a[j] + (m - sum)) < i){
					continue;
				}else{
					sum += i - a[j];
					nowans++;
				}
			}
		}
		if(nowans > ans) ans = nowans;
		nowans =0;
	}
	cout  << ans;

	return 0;
}

