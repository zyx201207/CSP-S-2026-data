#include<bits/stdc++.h>
#define ll long long
#define pll pair<long,long>
using namespace std;
const ll N=5*1e5;
ll n,m,a[N+7];
bool cmp(ll l,ll r){return l<r; }
ll cha[N+7];//cha前缀和 
bool check(ll num){
	//cout<<"CHECK:len = "<<num<<"\n";
	for(ll i=num;i<=n;i++){
		ll midd=i;
		//cout<<"midd = "<<midd<<"\n";
		//看区间[i-num+1,i]是不是小于等于m
		/*
		cout<<"   ["<<i-num+1<<","<<i<<"]:result="<<(cha[i]-cha[midd])-(a[midd]*(i-midd))+((a[midd]*(midd-(i-num)-1))-(cha[midd-1]-cha[i-num]))<<"\n";
		cout<<"        (cha[i]-cha[midd])="<<(cha[i]-cha[midd])<<"\n";
		cout<<"        (a[midd]*(i-midd))="<<(a[midd]*(i-midd))<<"\n";
		cout<<"(a[midd]*(midd-(i-num)-1))="<<(a[midd]*(midd-(i-num)-1))<<"\n";
		cout<<"  (cha[midd-1]-cha[i-num])="<<(cha[midd-1]-cha[i-num])<<"\n";
		*/
		if(((cha[i]-cha[midd])-(a[midd]*(i-midd))+((a[midd]*(midd-(i-num)-1))-(cha[midd-1]-cha[i-num])))<=m){
			//cout<<"   SUCCESS("<<midd<<")\n\n";
			return 1;
		}
	}
	//cout<<"   Not Found\n\n";
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	//cha[1]=a[1] !!!
	ll ls=a[1];
	for(int i=1;i<=n;i++){
		a[i]-=ls;
		//cout<<a[i]<<",";
		cha[i]=a[i]+cha[i-1];
		//prec[i]=cha[i]+prec[i-1];
	}
	//cout<<"\n";
	ll L=1,R=n;//长度求差是否小于等于m 
	while(L<R){
		ll mid=(L+R+1)>>1;
		if(check(mid)){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	printf("%lld",L);
	return 0;
}
//to 15:30