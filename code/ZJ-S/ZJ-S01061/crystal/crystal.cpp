#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fl;
ll n,m;
struct c{
	ll w;
	ll d;
}a[500005];
bool cmp(c x,c y){
	return x.w<y.w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=2;i<=n;++i){
		a[i].d=a[i].w-a[i-1].w;
		if(i>=3&&a[i-1].d!=a[i].d){
			fl=0;break;
		}
		else{
			fl=a[i].d;
		}
	}
	if(fl!=0){
		for(ll i=2;i<=n;i++){
			if(i%2==0){
				if(4*m>=fl*pow(i,2)&&4*m<=fl*(pow(i+1,2)-1)){
					cout<<i;break;
				}
			}
			if(i%2==1){
				if(4*m>=fl*(pow(i,2)-1)&&4*m<=fl*pow(i+1,2)){
					cout<<i;break;
				}
			}
		}
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}