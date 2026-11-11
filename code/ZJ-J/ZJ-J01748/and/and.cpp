#include <bits/stdc++.h>
using namespace std;
long long n,a[1000005],m,sum,cnt;
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==n){
		sum=a[1];
		for (int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if (m==1){
		for (int i=1;i<=n;i++){
			sum=max(a[i],sum);
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
