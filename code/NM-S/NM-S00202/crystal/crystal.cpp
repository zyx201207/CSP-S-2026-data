#include <bits/stdc++.h> 
using namespace std;

int n;
long long m1,m;
long long a[500001];
long long t = 0; 
int sum = 0;
int ans = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m1);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	m = m1;
	sort(a+1,a+n+1);
	sum = 1;
	for(int i = 1;i <= n;i++){
		if(m >= a[i] - a[i-1])
			for(int j = i-1;j >= 1;j--){
				if(m >= a[i] - a[j]){
					m -= a[i] - a[j];
					sum++;
				}
			}
		int t = 1;
		while(a[i+t] == a[i]){
			sum++,t++;
		}
		ans = max(ans,sum);
		sum = 1,t = 1;
		m = m1;
	} 
	printf("%d",ans);
	return 0;
}
