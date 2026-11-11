#include<bits/stdc++.h>
using namespace std;
const long long N=1e9;
long long n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	long long max=0;
	if(m==1){
		for(long long i=1;i<=n;i++){
			if(max<a[i]){
				max=a[i];
			}
		}
		cout << max;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				if(max<a[i]&a[j]){
					max=a[i]&a[j];
				}
			}
		}
	}
	return 0;
}
