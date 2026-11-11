#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[500005],s[500005],manbo;
int man(int l,int r,int x){
	if(l>=r)return r;
	int mid=(l+r)/2;
	if(a[x]*(x-mid+1)-s[x]+s[mid-1]<m)return man(l,mid,x);
	else if(a[x]*(x-mid+1)-s[x]+s[mid-1]>m)return man(mid+1,r,x);
	else return mid;//有时间看我代码不如去打树海界园，基建搞完了吗就来看
}//其实这个电脑上在C++里面打中文指针不在对应行看到的是棍木
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for(int i =1 ; i <= n ; i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i =1 ; i <= n ; i++)s[i]=s[i-1]+a[i];
	for(int i= 1 ; i <= n ; i++){
		manbo=man(1,i,i);
		ans=max(ans,1LL*(i-manbo+1));
	}
	cout << ans;
	return 0;
}