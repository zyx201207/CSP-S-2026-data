#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long g[N],s[N];
long long check(int x){
	long long s=0;
	for(int i=1;g[i]<=x;i++){
		s+=x-g[i];
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i];
	sort(g+1,g+1+n);
	bool f=1;
	for(int i=1;i<=n-2;i++){
		if(g[i+1]-g[i]!=g[i+2]-g[i+1]) f=0;
	}
	if(f){
		long long d=g[2]-g[1];
		long long s=0;
		for(int i=1;i<=n-1;i++){
			if(s+i*d>m){
				cout<<i-1;
				return 0;
			}
			s+=i*d;
		}
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(g[mid])>m) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
