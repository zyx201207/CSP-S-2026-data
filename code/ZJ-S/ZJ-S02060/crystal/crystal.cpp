#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500100],maxx=0,b[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);/**/
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		b[i]=a[i]+b[i-1];
	}
	for(ll i=1,j=1;i<=n;j++){
		if(a[i]*(i-j)-b[i]+b[j-1]<=m){
			while(a[i]*(i-j)-b[i]+b[j-1]<=m&&i<=n) {
				i++;
			}
			if(i>n) maxx=max(n-j,maxx);
			else maxx=max(i-j,maxx);
		}
	}
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
