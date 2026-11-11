#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],s[500010],l,r,ans;
inline ll read(){
	ll x;
	scanf("%d",&x);
	return x;
}
bool check(ll x){
	for(ll k=1;k<=n-x+1;k++){
		ll sum=s[k+x-1]-s[k-1];
		ll tgt=a[k+x-1]*x;
		if(tgt-sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1];
		s[i]+=a[i];
	}
	l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
/*
password:Oct31==Dec25?
wei yi yi ge zuo chu lai de
tmd kao chang ju ran mei guan shang ke ling
da yin ji hai shi bu shi fa chu xiang sheng
you dian tou yun
xi xi fu jiu shi ge ji
n m d 18:08 le gen wo men shuo T2yangli jie shi you wen ti
zen mo bu deng bi sai jie shu le zai shuo
you have no egg!
huan ying bao ming shan dong sheng shi yan zhong xue dong man she qing yin bu miao~(wei shen mo yao yan zou chun ri ying) wo shen mo dou hui zuo de

shuo shi hua , wo zhi shi  wu da wu zhuang jin le fu sai
shen bian hen duo bi wo qiang de da lao dou mei guo chu sai
bu guo shi cou shu de ba le
<=3= 

hai you 10min jiu jie shu le
zhu da qia tian tian kai xin   yong yuan bu si
*/
