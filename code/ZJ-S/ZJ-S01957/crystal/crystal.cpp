#include<bits/stdc++.h>
#define int long long
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;
int n,m,a[500005],f[500005];
bool check(int x,int y){
	return ((x-y+1)*a[x]-f[x]+f[y-1])<=m;
}
int bs(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(x,mid))r=mid-1;
		else{
			l=mid;
		}
	}
	return x-l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,bs(i));
	}
	cout<<ans<<endl;
	return 0;
}
/*






注意到使水晶消耗最少，必然是选择一个然后使能量小于它的增加，那么有不等式 Σi=y x a[x]-a[i]<=m，x-y最大
Σ i=y x a[x]-a[i]=(x-y+1)a[x]-S[x]-S[y-1]<=m
找y用二分
时间复杂度 O(nlogn)
好简单啊，比J T2简单
糖糖糖
woc,妈的检查一亿年才发现写错正负号。检查了1h 
CCF.money+=800
luogu uid :1781293
//	freopen
IAKIOI
完了，只有100pts了，希望有2=
有二等我给CCF上香 
没有就是guy 
AK的人格调∞ 
*/
