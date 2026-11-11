#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

long long a[N],b[N],c[N],d[N];
int n,m;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		a[i]=a[n]-a[i];
	}
	for(int i=1;i<=n-1;i++) b[i]=b[i-1]+a[i];
	b[n]=0x3f3f3f3f3f3f3f3f; 
	sort(b+1,b+1+n);
	for(int i=n;i>=1;i--){
		if(b[i]-i*a[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}

