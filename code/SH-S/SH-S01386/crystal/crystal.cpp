#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005];
long long m,ans,sum,cnt,sumb[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++){
		b[i] = a[i+1] - a[i];
		sumb[i] = sumb[i-1] + b[i];
		cout << b[i] << ' ' << sumb[i] << endl;
	}
	for(int i = 1;i < n;i++){
		sum = 0,cnt = 0;
		for(int j = i;j < n;j++){
			sum += sumb[j-1] - sumb[i-1];
			cnt++;
			if(sum > m) break;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
