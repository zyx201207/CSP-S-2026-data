#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;

template<typename T> void chkmax(T &x,T y) {if(y>x) x=y;}
template<typename T> void chkmin(T &x,T y) {if(y<x) x=y;}

int n;
ll m,a[N],pre[N],ans;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	
	ll l=1,r=1;
	
	for(r=1;r<=n;r++){
		while(pre[r]-pre[l-1]-(r-l+1)*a[r]<-m) l++;
		chkmax(ans,r-l+1); 
	} 
	
	cout<<ans<<'\n';
	
	return 0;
}

//Oct31==Dec25? 

