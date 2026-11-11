#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[2001000],sum=0;
int main(){
	/**/freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		sum=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			if(a[i+1]-a[i]<=k&&a[i+2]-a[i]<=k&&a[i+3]-a[i]>k&&a[3+i]-a[i+1]<=k&&a[i+3]-a[i+2]<=k) {
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
