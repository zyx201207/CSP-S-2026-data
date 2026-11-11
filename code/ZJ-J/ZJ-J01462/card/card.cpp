#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],lst[M],ans[M];
bool checkA(){
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1]) return 0;
	return 1;
}
void specialA(){
	int cnt=1;
	for(int i=1;i<=n+1;i++)
		if(a[i]!=cnt){
			cout<<i-1<<" ";
			cnt++;
		}
}
void solve(int l,int r){
	for(int i=1;i<=m;i++) lst[i]=r+1;
	for(int i=l;i<=r;i++){
		for(int j=lst[a[i]]+1;j<i;j++) lst[a[j]]=r+1;
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
		if(lst[i]!=r+1) ans[i]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(checkA()){
		specialA();
		return 0;
	}
	for(int i=1;i<=n;i++) solve(i,n);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}