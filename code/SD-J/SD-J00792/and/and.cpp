#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define fst ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N],maxx;
bool cmp(int a,int b){
	return a>b;
}
void solve(int x,int i,int k){
	if(k==0){
		maxx=max(maxx,x);
		return ;
	}
	for(int j=1;j<i;j++){
		solve(a[j]&x,j,k-1);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=m;i<=n;i++){
		solve(a[i],i,m-1);
	}
	cout<<maxx;
	return 0;
}
