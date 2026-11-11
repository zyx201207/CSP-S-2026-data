#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long di[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	

	sort(a,a+n);
	for(int i=0; i<n; i++){
		di[i]=a[i]-a[i-1];
	}
	
	int tmax=-1;
	for(int i=0; i<n; i++){
		int tc=0;
		int tsum=0;
		int d=1;
		for(int j=i; j<n; j++){
			tc+=di[j];
			tsum+=tc;
			if(tsum>m){
				tmax=max(d,tmax);
			} else {
				d++;
			}
		}
	}
	
	cout<<tmax;
	return 0;
}
