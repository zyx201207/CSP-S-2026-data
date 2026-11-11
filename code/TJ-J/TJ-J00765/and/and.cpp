#include<bits/stdc++.h>
#define ll long long
#define IMAX INT_MAX
#define IMIN INT_MIN
using namespace std;
ll n,m;
ll a[500009];
bool cmp(ll a,ll b){
	return a>=b;
}
ll andauto(ll p){
	ll jl=a[0];
	for(int i=1;i<p;i++){
		jl&=a[i];
	}
	return jl;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,&a[0]+n);
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			//a[i]=1;
		}
	}
	sort(a,a+n,cmp);
	int z=a[0],x=a[1];

	cout<<andauto(m);
	//continue;
	//break;

	fclose(stdin);
	fclose(stdout);
}
