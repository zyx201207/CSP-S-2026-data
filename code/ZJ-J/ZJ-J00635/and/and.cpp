#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(1<<i))==(1<<i)) cnt++; 
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++) b[j]=0;
			int sum=0;
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==(1<<i)) b[++sum]=a[j];
			}
			for(int j=1;j<=cnt;j++) a[j]=b[j];
			n=cnt;
		}
		if(n==m) break;
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans<<'\n';
	return 0;
}
