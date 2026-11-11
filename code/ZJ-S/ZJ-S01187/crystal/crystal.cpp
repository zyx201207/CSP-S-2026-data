#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,n,a[N],c[N],q[N],ans,p,t,s,b[N],anq;
map<int,int>js;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ans=n;
	anq=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		js[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[n]-a[i];
		q[i]=q[i-1]+c[i];
	}
	//for(int i=n-1;i>=1;i++) b[i]=b[i+1]+c[i];
	for(int i=n;i>0;i--){
		if(q[i]<=m){
			break;
		}
		else{
			q[i-1]=q[i]-(i-1)*(a[i]-a[i-1]);
			ans--;
		}
	}
	/*for(int i=1;i<=n;i++){
		if(b[i]<=m)break;
		anq--;
	}*/
	if(a[1]==a[n]) cout<<n; 
	else cout<<ans;
	return 0;
}
