#include <bits/stdc++.h>
using namespace std;
const unsigned long long N=2*1e6+10;
unsigned long long n,m,a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(unsigned long long i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		unsigned long long sum;
		for(unsigned long long i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		unsigned long long sum[n*n],ans=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum[ans]=a[i]&a[j];
			}
		}
		sort(sum+1,sum+1+ans);
		cout<<sum[ans];
	}
	return 0;
}
