#include<bits/stdc++.h>
using namespace std;
long long n,m,s,p,sum,g;
struct arr{
	long long a1;
	int a2[35];
}a[200005];
int b[35];
int f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i].a1;
		s = a[i].a1;
		for(int j = 1;j <= 32;++j){
			a[i].a2[j] = s&1;
			s /= 2;
		}
		
	}
	p = n;
	for(long long i = 32;i >= 1;--i){
		for(long long j = 1;j <= n;j++){
			if(!f[j] && a[j].a2[i] == 1){
				b[i]++;
			}
		}
		if(b[i] >= m){
			sum += pow(2,i-1);
			for(long long j = 1;j <= n;j++){
				if(!f[j] && a[j].a2[i] == 0){
					f[j] = 1;
				}
			}
		}
	}
	cout << sum;
	return 0;
}


