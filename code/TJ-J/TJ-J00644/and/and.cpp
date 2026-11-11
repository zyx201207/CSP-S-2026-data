#include<bits/stdc++.h>
using namespace std;

unsigned long long n,m,a[200005],ans=-1e9,cnt,idx;

void solve810(){
	for(int i=1;i<n;i++){
		cnt=a[i];
		for(int j=i+1;j<=n;j++){
			cnt=(cnt&a[j]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	exit(0);
}
void solve(int jia,int i){
	if(jia==m+1) return ;
	if(jia==1) cnt=a[i];
	for(int j=i+1;j<=n-m+jia;j++){
		cnt=(cnt&a[j]);
		solve(jia+1,j);
		--jia;
		ans=max(ans,cnt);
	}
	
}
void solve1112(){
	idx=1;
	for(int i=1;i<=n;i++){
		if(i==1) {
			cnt=a[2];
		}else {
			cnt=a[1];
		}
		for(int j=1;j<=n;j++){
			if(j==idx) continue;
			cnt=(cnt&a[j]); 
		}
		ans=max(ans,cnt);
		idx++;
	}
	cout<<ans;
	exit(0); 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=(cnt&a[i]);
		} 
		cout<<cnt;
		return 0;
	}
	if(m==2){
		solve810();
	}
	if(m==n-1){
		solve1112();
	}
	for(int i=1;i<=n-m+1;i++){
		solve(2,i);
	}
	cout<<ans;
	
	return 0;
} 
