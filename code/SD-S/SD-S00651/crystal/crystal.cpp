//构成基础差分数组 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m; 
vector<long long>k;
long long a[500005];
long long f[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i ++){
		long long o;
		scanf("%lld",&o);
		k.push_back(o);
	}
	sort(k.begin(),k.end());
	for(int i = 1;i <= n-1;i ++){
		a[i] = k[i] - k[i-1];
		f[i] = a[i];
	}
	int ans = 0;
	bool all_finish = true;
	for(int j = 1;j <= n - 1;j ++){
		bool flag = false;
		for(int i = 1;i + j <= n;i ++){
			f[i] = f[i] + a[i+j] * (j+1);
			if(f[i] <= m)flag = true;
		}
		if(flag == false){ans = j + 1;all_finish = false;break;}
	}
	if(all_finish == true){
		cout << n;
		return 0;
	}
	cout << ans << endl;
	return 0;
}

