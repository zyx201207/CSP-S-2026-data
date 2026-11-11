//SN-J00840 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ans=-1;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		ll x;
		scanf("%lld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i+m-1<n;i++){
		ll temp=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			temp&=a[j];
		}//这里需要一块一块的扫 差点被坑 
		ans=max(temp,ans);
	}
	printf("%lld\n",ans);
	return 0;
}//rp++ 复杂度是 n log n + m(n-m)? 最大到1e10++ (n=2e5,m=1e5)? 这怎么搞，放弃了 
