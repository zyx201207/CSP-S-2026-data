#include<iostream>
#include<algorithm>
using namespace std;
long long m,a[500005],x;int n,ans,cnt=1,lst,nxt=n,Ans;
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);a[n+1]=LLONG_MAX;a[0]=LLONG_MIN;
	for(int i=2;i<=n;i++)if(a[i]==a[i-1])cnt++;else{ans=cnt,x=a[i],lst=i-ans-1,nxt=i;while(1){
		long long p=LLONG_MAX,q=LLONG_MAX;
		if(nxt<=n)p=ans*(a[nxt]-x);
		if(lst>=1)q=x-a[lst];
		if(min(p,q)>m)break;
		else{if(p<=q)x=a[nxt++],m-=p;else lst--,m-=q;ans++;}}Ans=max(Ans,ans),cnt=1;}
	ans=cnt,x=a[n],lst=ans-1,nxt=n+1;while(1){
		long long p=LLONG_MAX,q=LLONG_MAX;
		if(nxt<=n)p=ans*(a[nxt]-x);
		if(lst>=1)q=x-a[lst];
		if(min(p,q)>m)break;
		else{if(p<=q)x=a[nxt++],m-=p;else lst--,m-=q;ans++;}}Ans=max(Ans,ans);
	cout<<Ans;
	return 0;}//大炸弹不是罪过！
