#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct itn{
	//    ________
	//  /____/__|_\ 
	// [*==*]@_]_@|
	// C A R   OVO
	
	ll x;//ÏÂ±ê
	ll s;//Êý 
};
bool cmp(itn a,itn b){
	return a.x<b.x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	int a[n+5],ans=0;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int k=a[0]+m/n;k<a[n-1];k++){
		itn t[n+5];
		int sum=0,tm=m;
		for(int i=0;i<n;i++){
			int temp=a[i]-k;
			temp*=-1;
			t[i].s=temp;
			t[i].x=i;
		}
		sort(t,t+n,cmp);
		for(int i=0;i<n;i++){
			if(tm<t[i].s)break;
			if(t[i].s<0)continue;
			tm-=t[i].s;
			sum++;
		}
		//if(sum>=ans)cout<<"ans "<<k<<endl;
		//else cout<<k<<endl;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
	//    ________
	//  /____/__|_\
	// [*==*]@_]_@|
}
