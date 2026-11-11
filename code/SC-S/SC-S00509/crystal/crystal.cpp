#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans = 0;
	for(int i=1;i<=n;i++){ //Iter: target min->max
		long long nowm = m;
		long long nowans = 0;
		long long target = a[i];
		for(int j=i;j>=1;j--){ // Iter: |target-real| min->max
			if(nowm >= target-a[j]){ // The a[j] is useable
				nowm -= target-a[j];
				nowans++;
			}
			else break;
		}
		ans = max(ans,nowans);
	}
	cout<<ans<<endl;
	return 0;
}