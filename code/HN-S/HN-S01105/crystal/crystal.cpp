#include <bits/stdc++.h>
using namespace std;
 
long long a[500005];
long long pre[500005];

long long cal(long long p,long long k){
	long long w=1LL*(k-p+1)*a[k]-pre[k]+pre[p-1];
	return w;
}
//复杂度：O(n*logn); 都是排序的复杂度 

void solve(){
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long pos=0;
	long long l=1,r=1;
	while(l<=r and l<=n and r<=n){
		if(cal(l,r)>m){
			l++;
		}else{
			r++;
		}
		pos=max(pos,r-l+1);
		
	}
	cout<<pos-1;
	return ;
	
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
