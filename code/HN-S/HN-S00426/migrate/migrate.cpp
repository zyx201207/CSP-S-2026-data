#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t;
	cin>>c>>t;
	for(int fd=0;fd<t;fd++){
		long long n,d,h=0;
		cin>>n>>d;
		long long x[n];
		for(int i=0;i<n;i++)cin>>x[i];
		long long dx[n-1];
		for(int i=1;i<n;i++){
			dx[i-1]=x[i]-x[i-1];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int lmi=(x[j]-x[i]+d-1)/d;
				if((lmi!=(x[j]-x[i])/d) && (j-i==lmi+1))h++;
			}
		}
		cout<<h<<endl;
	}
	return 0;
}

