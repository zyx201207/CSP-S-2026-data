#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct z{
	int shu,ji;
}a[N];
bool cmp(z x,z y){
	if(x.ji!=y.ji)return x.ji>y.ji;
	return x.shu>y.shu;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu;
		int x=a[i].shu;
		ll cnt=0;
		while(x){
			if(x%2==1){
				cnt++;
			}
			x/=2;
		}
		a[i].ji=cnt;
	}
	sort(a+1,a+1+n,cmp);
	ll ans=a[1].shu;
	for(int i=2;i<=m;i++){
		ans&=a[i].shu;
	}
	cout<<ans;
	return 0;
}
