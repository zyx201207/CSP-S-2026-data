#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000010];
bool zrf(int n){
	int k=x[2]-x[1];
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=k)return 0;
	}
	return 1;
}
int ma(int n){
	int k=x[2]-x[1];
	for(int i=3;i<=n;i++){
		k=min(k,x[i]-x[i-1]);
	}
	return k;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int mi=ma(n);
		if(mi>d){
			cout<<0<<"\n";
			continue;
		}
		else if(x[n]-x[1]<d){
			cout<<"0\n";
			continue;
		}
		else if(n<=3){
			cout<<0<<"\n";
		}
		else if(n==4){
			int to=x[2]-x[1];
			int tt=x[3]-x[2];
			int ft=x[4]-x[3];
			if((to+tt<=d&&ft<d)&&(ft+tt<=d&&to<d)){
				cout<<1<<"\n";
				continue;
			}
			else{
				cout<<0<<"\n";
				continue;
			}
		}
		else if(zrf(n)){
			int kk=x[2]-x[1];
			int ans=0;
			int fast=d/kk;
			ans=n-fast-1;
			//cout<<fast<<" flag\n";
			if(ans<0){
				cout<<0<<"\n";
				continue;
			}
			if(fast!=2&&fast!=3){
				cout<<0<<"\n";
				continue;
			}
			if(fast==3)ans--;
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
