#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N],aans,mm = -2e18,xx = 2e18,zz,c[N],pre[N];//l,r,z,ans,lm,sa = 0;
bool cmp(long long x,long long y){
	if(x > zz and y > zz)
		return x < y;
	if(x > zz or y > zz)
		return x < y;
	return x > y;
}
//void dfs(long long l,long long r,long long sa){
//	long long ans = 0;
//	long long lm = m;
//	long long z = pre[r] - pre[l-1];
//	z = z / (r - l + 1);
//	z = upper_bound(c + 1,c + n + 1,z) - c;
//	//z = c[z];
//	//cout<<c[z]<<endl;
//	zz = c[z];
//	//cout<<l<<" "<<z<<" "<<r<<" "<<deep<<endl;
//	sort(a + 1,a + n + 1,cmp);
//	for(int i = 1; i <= n; i ++){
//		if(zz - a[i] < 0)
//			break;
//		if(lm - (zz - a[i]) < 0){
//			break;
//		}
//		//a[i] = z;
//		lm -= zz - a[i];
//		ans ++;}
//	//cout<<ans<<" "<<l<<" "<<z<<" "<<r<<" "<<deep<<endl;
//	if(ans < sa)
//		return;
//	aans = max(ans,aans);
//	if(l == z or r == z)
//		return;
//	dfs(z,r,ans);
//	dfs(l,z,ans);
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++){
		cin>>a[i];
		c[i] = a[i];
		mm = max(a[i],mm);
		xx = min(a[i],xx);}
	sort(c + 1,c + n + 1);
	if(n <= 5000){
	for(long long i = 1; i <= n; i ++){
		zz = c[i];
		long long ans = 0;
		long long lm = m;
		sort(a + 1,a + n + 1,cmp);
		//cout<<zz<<endl;
//		for(int j = 1; j <= n; j ++)
//			cout<<a[j]<<" ";
		//cout<<endl;
		for(int j = 1; j <= n; j ++){
			if(zz - a[j] < 0)
				break;
			if(lm - (zz - a[j]) < 0){
				break;
			}
			//a[i] = z;
			lm -= zz - a[j];
			ans ++;}
		aans = max(ans,aans);
	}}
	else {
		zz = c[n];
		long long ans = 0;
		long long lm = m;
		sort(a + 1,a + n + 1,cmp);
		for(int j = 1; j <= n; j ++){
			if(zz - a[j] < 0)
				break;
			if(lm - (zz - a[j]) < 0){
				break;
			}
			//a[i] = z;
			lm -= zz - a[j];
			ans ++;}
		aans = max(ans,aans);
	}
//	l = xx;
//	r = mm;
//	dfs(1,n,0);
//	while(l < r){
//		ans = 0;
//		lm = m;
//		z = (l + r) / 2 + (l + r) % 2;
//		zz = z;
//		sort(a + 1,a + n + 1,cmp);
//		for(int i = 1; i <= n; i ++){
//			if(z - a[i] < 0)
//				break;
//			if(lm - (z - a[i]) < 0){
//				break;
//			}
//			//a[i] = z;
//			lm -= z - a[i];
//			ans ++;}
//		cout<<ans<<" "<<l<<" "<<z<<" "<<r<<" "<<sa<<endl;
//		aans = max(ans,aans);
//		if(l == z or r == z)
//			break;
//		sa = ans;
//		}
	cout<<aans;
	return 0;
}
