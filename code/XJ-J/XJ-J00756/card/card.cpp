#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long sum;
long long cnt;
long long c[500005];
long long maxn;
int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	cin >> n >> m;
	for(long long i=1; i<=n; i++){
		cin >> a[i];
	}
	cnt = 1;
	b[1] = a[1];
	sum++;
	for(long long i=1; i<=n; i++){
		for(long long j=cnt; j<=n; j++){
			for(long long k=1; k<=sum; k++){
				if(b[k]==a[cnt]){
					for(long long l=k; l<=sum; l++){
						b[l]=0;
						sum--;
					}
			}
			b[sum+1] = a[cnt];
			}
		}
		cnt++;
		for(int i=1; i<=sum; i++){
			c[b[i]]++;
			if(b[i]>maxn) maxn = b[i];
		}
	}
	for(int i=1; i<=maxn; i++){
		cout << c[i];
		cout << ' ';
	}
	return 0;
}