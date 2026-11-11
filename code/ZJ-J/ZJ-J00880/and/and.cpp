#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
bool f=1;
struct Node{
	int num,bit;
}a[N];
bool check(int x){
	while(x!=1){
		if(x%2)
			return 0;
		x/=2;
	}
	return 1;
}
bool cmp(Node x,Node y){
	if(x.bit==y.bit)
		return x.num>y.num;
	return x.bit>y.bit;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		if(a[i].num+1!=i)
			f=0;
		a[i].bit=__builtin_popcount(a[i].num);
	}
	if(f&&check(n)){
		cout<<n-m;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++)
//		cout<<a[i].num<<' ';
	int ans=a[1].num;
	for(int i=2;i<=m;i++)
		ans&=a[i].num;
	cout<<ans;
	return 0;
}
