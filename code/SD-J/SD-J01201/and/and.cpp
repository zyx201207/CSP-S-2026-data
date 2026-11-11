#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}sort(a+1,a+n+1);
	if (m==1){
		cout <<a[n];
		return 0;
	}if (m==n){
		sum=a[1];
		for (int i=1;i<=n;i++){
			sum=sum&a[i];
		}cout <<sum;
		return 0;
	}if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				sum=a[i]&a[j];
				maxx=max(maxx,sum);
			}
		}cout <<maxx;
		return 0;
	}if (m==n-1){
		sum=a[2];
		for (int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		for (int i=2;i<=n;i++){
			sum=a[1];
			for (int j=1;j<=n;j++){
				if (j!=i) sum=sum&a[j];
			}maxx=max(sum,maxx);
		}cout <<maxx;
		return 0;
	}
	return 0;
}
