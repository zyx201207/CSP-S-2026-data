#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long ans=1;
long long m,a[N],b[N];
long long ss(int x){
	long long zs=0;
	for(long long i=0;;i++){
		if(zs+b[x+i+1]<=m){
			zs+=b[x+i+1];
		}
		else{
			return i;
		}
	}
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin>>n>>m;
	if(n==1){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		ans=max(ans,ss(i));
	}
	cout<<ans-500005;
	return 0;
}
