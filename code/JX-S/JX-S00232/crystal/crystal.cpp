#include<bits/stdc++.h>
using namespace std;
const max=10000000000005;
void abc(int b){
	if(b>=0) return b;
	if(b<0) return -b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[max[,c[max],d[max];
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(n%2)c[i]=abc(a[i]-a[n/2+1]);
		else c[i]=abc(a[i]-a[n/2]);
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(m){
			m-=c[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
