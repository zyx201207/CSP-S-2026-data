#include<bits/stdc++.h>
using namespace std;
int a[200007];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f1=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)f2=1;
		if((a[i]+1)&-(a[i]+1)!=a[i]+1)f1=1;
	}
	if(!f1||m==1){
		int mx=a[1];
		for(int i=2;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(!f2){
		int f[4]={};
		for(int i=1;i<=n;i++){
			f[a[i]]++;
		}
		int ans=0;
		if(m>f[3]){
			if(m>f[3]+f[2]){
				;
			}else ans=max(ans,2);
			if(m>f[3]+f[1]){
				;
			}else ans=max(ans,1);
		}else ans=3;
		cout<<ans;
		
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,i&j);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

