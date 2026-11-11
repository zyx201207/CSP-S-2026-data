#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n, m;
struct node{
	int sum, first, x, l;
}a[N];
bool cmp(node x,node y){
	if(x.l!=y.l) return x.l<y.l;
	if(x.sum!=y.sum) return x.sum<y.sum;
	return x.first>y.first;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int max_len=0;
	for(int i=1;i<=n;i++) cin>>a[i].x;
	for(int i=1;i<=n;i++){
		int cnt=0,a1=a[i].x;
		while(a1&(a1-1)){
			a1=a1&(a1-1);
			cnt++;
		} 
		a[i].sum=cnt+1;	
		cnt=0,a1=a[i].x;
		while(!(a1&1)){
			a1=a1>>1,cnt++;
		}
		a[i].first=cnt+1;
		a1=a[i].x,cnt=0;
		while(a1){
			a1=a1>>1,cnt++;
		}
		a[i].l=cnt;
		max_len=max(max_len,cnt);
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	ans=pow(2,max_len)-1;
	for(int i=n;i>=n-m+1;i--){
		ans=(ans&a[i].x);
	}
	cout<<ans;
	return 0;
}
