#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];char f[N];
void solve(){
	long long ans1=0,ans2=0;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>f[i];
	int k=n/2;
	if(n%2!=0) k++;
	int r=0;
	for(int i=n;i>=k;i--){
		int l1=a[n-i+1],l2=a[i];
		char r1=f[n-i+1],r2=f[i];
		if(r1==r2&&l2>=l1) continue;
		if(l1!=l2||r1!=r2){
			if(i!=n) r-=l2;
			r+=abs(l1-l2);
			ans1+=l1;
		}
	}
	for(int i=1;i<=k;i++){
		int l1=a[i],l2=a[n-i+1];
		char r1=f[i],r2=f[n-i+1];
		if(r1==r2&&l1>=l2) continue;
		if(l1!=l2||r1!=r2){
			if(i!=n) r-=l1;
			r+=abs(l1-l2);
			ans2+=l2;
		}
	} 
	cout<<min(ans1,ans2)<<endl;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
