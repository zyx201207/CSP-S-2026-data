#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn];
long long cnt;
bool erfen(int x){
	long long u=0,v=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			u+=x-a[i];
			v++;
		}
	}
	if(u<=m){
		cnt=v;
		return 1;
	}
	return 0;
}
long long l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		l=min(l,a[i]);
		r=max(r,a[i]);
	} 
	bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n+1-i]){
			f=0;
		}
	}
	if(f==1){
		cout<<n;
		return 0;
	}
	
	while(l<r){
		long long mid=((l+r)/2);
		if(erfen(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<cnt;
	return 0;
} 
