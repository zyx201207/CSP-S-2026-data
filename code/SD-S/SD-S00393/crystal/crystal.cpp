#include<bits/stdc++.h>//RP++ 
using namespace std;
#define ll long long
#define maxn 500050
ll a[maxn],b,c,d,i,j,k,m,n,ans,sum=-1e18,tot=1e18,cnt,js,l,zhuihe[maxn],r,p,x,y,t;
bool pad(ll x){//x长度是否成立 
	ll sum=1e18; //sum记录最小操作数 
	for(i=1,j=x;i<=1+n-x,j<=n;i++,j++){//遍历所有长度为x序列 
		sum=min(a[j]*x-zhuihe[j]+zhuihe[i-1],sum);//x个数的值都为末尾的数，再减去已有的值 
	}
	if(sum<=m)return true;//判断是否合规 
	return false;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum=max(sum,a[i]);//最值
		tot=min(tot,a[i]);
	}
	if(sum-tot<100){
		for(i=1;i<=100;i++){//特殊点：绝对值最大小于100 
			js++;
		}
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)zhuihe[i]=zhuihe[i-1]+a[i];
	l=1,r=n;
	while(l<=r){//枚举数量 
		ll mi=(l+r)/2;
		if(pad(mi))ans=max(mi,ans),l=mi+1;
		else r=mi-1;
	}
	cout<<ans<<endl; 
	return 0;
} 
