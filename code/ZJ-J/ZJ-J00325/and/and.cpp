#include<bits/stdc++.h>
using namespace std;
int n,m;
int MAX=-1;
int a[500000];
int b[500000];
void DFS(int i,int sum,int cnt) {
	if(cnt+n-i+1<m) return;
	if(cnt>m) return;
	if(i>n) {
		if(cnt==m) MAX=max(MAX,sum);
		return;
	}
	b[i]=0;
	DFS(i+1,sum,cnt);
	b[i]=1;
	if(sum==0) DFS(i+1,a[i],cnt+1);
	else DFS(i+1,sum&a[i],cnt+1);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1) cout<<a[n];
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else {
		DFS(1,0,0);
		cout<<MAX;
	}
	return 0;
}