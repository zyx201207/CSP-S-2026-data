#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,m;
struct Node{
	LL num,js;
	bool operator<(const Node &o)const{
		return js>o.js||(js==o.js&&num>o.num); 
	}
}a[N];
LL ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].num);
		int k=a[i].num;
		while(k){
			if(k&1)a[i].js++;
			k>>=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		if(ans==0)ans=a[i].num;
		else ans=ans&a[i].num;
	}
	printf("%lld",ans); 
	return 0;
} 
