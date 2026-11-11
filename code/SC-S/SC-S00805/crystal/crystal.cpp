#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m,k;
int a[maxn];
int pre[maxn];
bool fi,fa;
void solve1(){
	int l=1;
	for(int i=1;i<=n;i++){
		if(i*(i+1)<=m*2){
			l=i+1;
		}
	}
	int ans;
	ans=l;
	cout<<ans;
	return;
}
void solve2(){
	int l=0;
	for(int i=1;i<=n;i++){
		if(i*(i+1)*k<=m*2){
			l=i+1;
		}
//		cout<<l<<' ';
	}
	int ans;
	ans=l;
	cout<<ans;
	return;
}
bool check(int mid){
//	cout<<1;
//	cout<<mid<<" "<<a[mid]<<" "<<pre[mid]<<"\n";
	return m>=abs(mid*a[mid]-pre[mid]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]+=pre[i-1]+a[i];
		if(a[i]!=i)fi=1;
//		cout<<pre[i]<<' ';
	}
	k=a[2]-a[1];
	for(int i=n;i>1;i--){
		if(k!=a[i]-a[i-1])fa=1;
	}
	if(fi==0){
		solve1();
	}else if(fa==0){
		solve2();
	}else{
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r+1)>>1;
			if(check(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<r;
	}
	return 0;
}
/*
5 4
1 2 3 4 5
3


5 40
10 15 20 25 30
4

4 100
40 60 80 100
3
*/