#include<bits/stdc++.h>
#define AKCSPS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define int long long
using namespace std;//75~100pts
int a[500010],cha[500010];
signed main(){
	AKCSPS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flagA=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])	flagA=0;
	}
	if(flagA==1){
		if(n%2==1){
			int ans;
			for(ans=1;ans<=n-1;ans++){
				if((ans+1)*ans/2>m)	break;
			}
			cout<<ans;
			return 0;
		}
	}
	if(n>5000){
		cha[1]=0;
		for(int i=2;i<=n;i++){
			cha[i]=a[i]-a[i-1];
		}
		int t=m,noww=1;
		while(1){
			if(noww>n)	break;
			if(m<cha[noww+1]*noww) break;
			m-=cha[noww+1]*noww;
			noww++;
		}
		cout<<noww;		
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=i;j++){
				sum+=a[i]-a[j];
			}
			if(sum<=m){
				ans=max(ans,i);
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
5 5
-1 -2 -4 -8 -9

1 2 4 8 9



*/
