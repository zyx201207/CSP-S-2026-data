#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],s[maxn];
bool check(int len){
	int res=0;
	for(int r=len;r<=n;r++){
		int l=r-len+1;
		if(a[r]*len-(s[r]-s[l-1])<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
喵区也来打CSP-S喵 Ｏ(≧▽≦)Ｏ 找到这个表情了，但总感觉怪怪的，不可爱了 QAQ 
二分排个序 
abs(s[r]-s[r-len]-k*len)
这是分段函数随便做 

哦哦是+1啊 
14:47
*/
