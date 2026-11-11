#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxa,maxb,maxc,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		maxa = max(maxa,a[i]);
	}
	maxc = a[1]&a[2];
	for(int i = 2; i<=n; i++){
		int mab = a[i]&a[i-1];
		if(mab>=maxb){
			maxb = a[i]&a[i-1];
		}
		maxc = maxc&a[i];
	}
	if(m==1){
		cout << maxa;
		return 0;
	}else if(m==2){
		cout << maxb;
		return 0;
	}else if(m==n){
		cout << maxc;
		return 0;
	}
	for(int i = 1; i<=n; i++){
		long long b = a[i];
		for(int j = i+1; j<=n; j++){
			long long c = a[j];
			for(int p = j+1; p<=n; p++){
				long long d = a[p]&b;
				d = d&c;
				ans = max(ans,d);
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
