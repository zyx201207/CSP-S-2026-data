#include<bits/stdc++.h>
using namespace std;
const int N=5E5+10;
#define ll long long
ll n,m;
ll a[N],ans;
bool check(int Mid){
	int SumNeed=0;
	for(int i=1;i<=n;i++){
		SumNeed+=max(0ll,Mid-a[i]);
		if(Mid-a[i]<=0)
			return SumNeed<=m;
	}
//	cout<<"---"<<SumNeed<<"---\n";
	return SumNeed<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll L=a[1],R=a[n]; 
	while(L<R){
		int Mid=(L+R+1)>>1;
//		cout<<L<<" "<<Mid<<" "<<R<<"\n";
		if(check(Mid)){
			L=Mid;
		}
		else{
			R=Mid-1;
		}
	}
//	cout<<n<<"\n";
//	cout<<L<<" "<<R<<"\n";
	for(int i=1;i<=n;++i){
		if(a[i]<=L){
			ans++;
//			cout<<"+++\n";
		}
	}
	printf("%lld",ans);
	return 0;
}
