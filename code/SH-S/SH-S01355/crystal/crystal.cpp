#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500005], b[500005];
long long ans, l, r;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1, a+1+n);
	
	for(int i=1;i<n;i++) {
		b[i]=a[i+1]-a[i];
	}
	b[n]=-1;
	
	for(int i=2;i<=n;i++){
		long long k=m, cnt=1, j=i-1, same=0;
		if(b[i]==0) continue;
		while(k>=a[i]-a[j]&&j>=1){
			if(b[j]==0) {
				same++; cnt--;
			}
			k-=a[i]-a[j]; 
			cnt++; j--;
		}
		cnt+=same;
		if(cnt>ans) {
			ans=cnt; r=i; l=j+1;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
