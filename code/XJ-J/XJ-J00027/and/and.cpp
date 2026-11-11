#include<bits/stdc++.h>
using namespace std;
struct pp{
	long long v,l,s;
}a[200005];
long long n,m,ans;
bitset<101>b;
int len(int x){
	long long b = 1,i = 0;
	while(b <= x){
		b *= 2;
		i++;
	}
	return i;
}
bool cmp(pp x,pp y){
	if(x.s != y.s)return x.s > y.s;
	return x.l > y.l;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].v;
		b = a[i].v;
		a[i].l = len(a[i].v);
		a[i].s = b.count();
	}
	sort(a+1,a+n+1,cmp);
	ans = a[1].v;
	for(int i = 2;i <= m;i++){
		ans &= a[i].v;
	}
	cout << ans;
	return 0;
} 
