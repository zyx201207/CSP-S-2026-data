#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int id,w;};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	if(c==13||c==14){
	while(T--){
		int n,d;cin>>n>>d;
		vector<int>x(n+1,0);
		vector<bool>pd(n+1,0);
		for(int i=1;i<=n;i++)cin>>x[i];
		int l=1,r=1,ans=0;
		while(l<n&&r<=n){
			while(r+1<=n&&x[r]-x[l]<=d)r++;
			ans+=n-r;l++;
		}
		cout<<ans<<"\n";
	}
	return 0;
	}
	while(T--){
		int n,d;cin>>n>>d;
		vector<int>x(n+1,0),val(n+1,1);
		int del=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0,j=1,l=1,r=1;
		for(int i=1;i<=n;i++){
			while(j+1<=n&&x[j+1]-x[i]<=d)j++;
			if(j-i==1){val[j]+=val[i];continue;}
			while(r+1<=n&&r<=j-1)r++;
			while(r+1<=n&&x[r+1]-x[j-1]<=d)r++;
			l=j;
			if(j-i>2)while(l+1<=n&&x[l+1]-x[j-2]<=d)l++;
			ans+=val[i]*(r-l);
		}
		cout<<ans<<"\n";
	}
	return 0;
}