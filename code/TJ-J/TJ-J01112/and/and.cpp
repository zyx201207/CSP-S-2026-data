#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int b[100005];
int c[100005];
int zc[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int cnt =1;
		while(a!=0){
			int f = a[i]%2;
			int j = 1;
			c[j]=f;
			j++;
			cnt++;
			a[i]/=2;
		}
		int sum = 0;
		for(int k = cnt;k>=1;k--){
			int o = 10;
			for(int g = 1;g <= k-1;g++){
				o*=10;
			} 
			sum+=c[k]*o;
		}
		int u = 1;
		zc[u]=sum;
		u++;
	}
	
	return 0;
} 
