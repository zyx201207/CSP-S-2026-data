#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=1,sum,maxn;
long long a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 2; i <= n; i++){
		c[i-1] = a[i] - a[i-1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			sum+=c[j]*(j-i+1);
			if(sum<=m){
				cnt++;
				if(cnt==n){
					cout << cnt;
					return 0;
				}
			}
			else{
				maxn = max(maxn,cnt);
				cnt=0;
				sum=0;
				break;
			}
		}
	}
	cout << maxn;
	return 0;
} 
