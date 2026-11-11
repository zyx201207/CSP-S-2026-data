#include<bits/stdc++.h>
using namespace std;
long long n,m,t[500010];
struct node{
	long long ma,x,y;
}a[1000010];
void build(int k,int x,int y){
	int mid=(x+y)>>1;
	if(x==y){
		a[k].ma=t[x];
		a[k].x=x;
		a[k].y=y;
		return;
	}
	build(k<<1,x,mid);
	build(k<<1|1,mid+1,y);
	a[k]={max(a[k<<1].ma,a[k<<1|1].ma),x,y};
}
long long query(int k,int x,int y){
	if(a[k].x>=x&&a[k].y<=	y){
		return a[k].ma;
	}
	long long ma=-1e12-1;
	int mid=(a[k].x+a[k].y)>>1;
	if(x<=mid)ma=max(ma,query(k<<1,x,y));
	if(y>mid)ma=max(ma,query(k<<1|1,x,y));
	return ma;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i]);
	}
	build(1,1,n);
//	for(int i=1;i<=n*2;i++){
//		cout<<a[i].ma<<" "<<a[i].x<<" "<<a[i].y<<"\n";
//	}
	long long i=1,j=1,num=0,ma=t[1],ans=0;
	while(i<=j&&j<=n){
		if(num<=m){
			if(t[j]>ma){
				num+=(j-i)*(t[j]-ma);
				ma=t[j];
			}else{
				num+=(ma-t[j]);	
			}
		//	cout<<i<<" "<<j<<" "<<num<<endl; 
			if(num>m){
				i++;
			}else{
				ans=max(ans,j-i+1);
				j++;
			}
		}else{
			if(t[i-1]>=ma){
				num-=(j-i+1)*(t[i-1]-query(1,i,j));
				ma=query(1,i,j);
			}else{
				num-=(query(1,i,j)-t[i-1]);
			}
//			cout<<i<<" "<<j<<" "<<num<<endl; 
			if(num>m){
				i++;
			}else{
				ans=max(ans,j-i+1);
				j++;
			}
		}
	}printf("%lld",ans);
	return 0;
}
