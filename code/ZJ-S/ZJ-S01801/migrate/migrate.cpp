#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N];
void specialA(){
	if(n<=3){cout<<"0"<<"\n";return;}
	int dt=a[2]-a[1];
	int x=d/dt,ans=0;
	if(x<=1) cout<<"0"<<"\n";
	else cout<<max(0ll,n-2*x+1)<<"\n";
	return;
}
bool check(int x,int y){
	int cnt=0,l=x,r=x,lenth=0;
	for(int i=x+1;i<=y;i++){
		lenth+=(a[i]-a[i-1]);
		if(lenth<=d) continue;
		if(l!=1){
			lenth-=(a[i]-a[i-1]);
			for(int j=l-1;j>r;j--){
				if(a[l]-a[j]+lenth<=d) cnt++;
				if(cnt>1) return false;
			}
		}
		r=l,l=i-1,lenth=a[i]-a[i-1];
		if(lenth>d) return false;
	}
	if(l!=1){
		for(int j=l-1;j>r;j--){
			if(a[l]-a[j]+lenth<=d) cnt++;
			if(cnt>1) return false;
		}
	}
	if(cnt==1) return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int dt;bool vis=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2) dt=a[i]-a[i-1];
			if(i>2&&(a[i]-a[i-1])!=dt) vis=0;
		}
		if(vis){specialA();continue;}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
