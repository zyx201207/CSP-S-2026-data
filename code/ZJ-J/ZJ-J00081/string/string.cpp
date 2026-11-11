#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
struct Node{
	int num;
	char ch;
}a[N];
void solve(){
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].num,&a[i].ch);
	}
	int ans=0;
	int l=1,r=n;
	while(l<r){
		int mi=min(a[l].num,a[r].num);
		if(a[l].ch!=a[r].ch){
			ans+=mi;
		}
		int pl=l,pr=r;
		a[l].num-=mi;
		a[r].num-=mi;
		if(a[l].num==0){
			l++;
		}
		if(a[r].num==0){
			r--;
		}
	}
	printf("%lld",ans);
	return;
}
signed main(){
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	solve();
	return 0;
}
