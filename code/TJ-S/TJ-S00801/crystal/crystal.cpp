#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long delta[n+5];
	long long nums[n+5];
	memset(delta, 0, sizeof(delta));
	memset(nums, 0, sizeof(nums));
	for(int i=1; i<=n; i++){
		long long num;
		cin >> num;
		nums[i]=num;
	}
	sort(nums+1, nums+n+1);
	for(int i=1; i<=n; i++){
		delta[i]=nums[i]-nums[i-1];
	}
	delta[1]=0;
	int pre[n+5];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+(i-1)*delta[i];
	}
	int maxn=1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(pre[i]-pre[j]<=m){
				maxn=max(maxn, i-j+1);
			}
		}
	}
	cout << maxn;
	
	return 0;
}
