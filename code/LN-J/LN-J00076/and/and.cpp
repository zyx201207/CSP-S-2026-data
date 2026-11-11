#include<bits/stdc++.h>
using namespace std;
long long a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if(n==m){
		long long t=a[1];
		for(int i=2;i<=n;i++){
			t=t&a[i];
		}
		cout << t;
		return 0;
	}
	if(m==2){
		long long t=-99999;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				t=max(t,i&j);
			}
		}
		cout << t;
		return 0;
	}		
	return 0;
}
