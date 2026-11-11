#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=5e5+10;
namespace STD{
	/*
	首先你考虑只能增加,
	那排序逐个处理，然后按维护一个队列即可 
	考虑对于一个变量要增加都增加全局加计入一个lzy即可 
	
	*/
	ll n,x;
	__int128 a[N],h=1,t=0;
	__int128 q[N],m;
	void work(){
		cin>>n>>x;m=x;
		for(ll i=1;i<=n;i++){
			cin>>x;
			a[i]=x;	
		}
		sort(a+1,a+n+1);
		__int128 sum=0,ans=0;
		for(ll i=1;i<=n;i++){
			sum+=(a[i]-a[i-1])*((t-h+1));
			q[++t]=i;
			while(h<=t&&sum>m){
				sum-=a[i]-a[q[h]];				
				++h;
			}
		//	cout<<(ll)h<<" "<<(ll)t<<"\n"; 
			ans=max(ans,t-h+1);			
		}
		cout<<(ll)ans<<"\n";
	}
}
void rw(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
rw();
	int T=1;//cin>>T;
	while(T--) STD::work();
	return 0;
}


