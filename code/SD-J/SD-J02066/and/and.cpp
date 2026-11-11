#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct node{
	long long num;
	int b;
	friend operator < (node a,node _){
		return a.num<_.num;
	}
}b[N];
long long a[N];
long long hzt;
int count(long long x){
	int ans=0;
	while(x){
		x>>=1;
		ans++;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i].b=i;
		b[i].num=a[i]<<count(a[n])-count(a[i]);
	}
	sort(b+1,b+1+n);
	hzt=a[b[n].b];
	for(int i=n;i>=n-m+1;i--){
		hzt&=a[b[i].b];
	}
	cout<<hzt<<'\n';
	return 0;
} 
