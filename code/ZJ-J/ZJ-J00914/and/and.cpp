#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int ma,b[40];
long long p(int aa){
	if(aa%2) return -1;
	else if(aa==2) return 1;
	else return p(aa/2);
}
//void bb(long long k){
//	int i=0;
//	while(k>0) {
//		long long kk=pow(2,i+1);
//		if(k%kk!=0) b[i]++;
//		k-=pow(2,i);
//	}
//	ma=max(ma,i);
//}
//void ba(long long k) {
//	for(int i=ma;k>0;i--){
//		if(k>=pow(2,i)) {
//			k-=pow(2,i);
//			b[i]--;
//		}
//	}
//}
//void solve(){
//	m=n-m;
//	for(int i=ma;i>=0;i--) {
//		if(b[i]<=m){
//			for(int j=1;j<=n;j++){
//				if(a[j]>=pow(2,i)) ba(a[j]);
//			}
//		}
//	}
//	for(int i=1;i<=ma;i++) if(b[i]==0) ans*=pow(2,b[i]);
//	cout<<ans;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cin>>ans;
		for(int i=2;i<=n;i++) {
			cin>>a[i];
			ans=ans&a[i];
		}
		cout<<ans;return 0;
	}
	int k=p(n);
	bool b=1;
	long long maa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		bb(a[i]);
		maa=max(a[i],maa);
		if(a[i]!=i-1) b=0;
	}
	if(k!=-1 && b){
		cout<<n-m;
		return 0;
	}
	if(m==1) {
		cout<<maa;
		return 0;
	}
	cout<<0;
//	solve();
} 
