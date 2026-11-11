#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
const int N=2e5+5;
using namespace std;
ll n,m,ans,cnt,tmp;
struct node{
	ll a,b;
}a[N];
bool cmp(node x,node y){
	if(x.b!=y.b) return x.b>y.b;
	return x.a>y.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].b=log2(a[i].a);
	}
	sort(a+1,a+n+1,cmp);
	while(1){
		ll ans=0,tmp=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt==m){
				cout<<ans;
				return 0;
			}
			if(tmp!=a[i].b){
				tmp=a[i].b;
				cnt=1;
				ans=a[i].a;
			}else{
				ans&=a[i].a;
				cnt++;
			}
		}
		tmp=a[1].b;
		for(int i=1;tmp==a[i].b;i++){
			int k=log2(a[i].a);
			a[i].a-=pow(2,k);
			a[i].b=log2(a[i].a);
		}
		sort(a+1,a+n+1,cmp);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
