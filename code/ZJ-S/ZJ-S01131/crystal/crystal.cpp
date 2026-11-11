#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[500010],t,ma,ans,mi,sum,sum2;
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		t=1;
		while(t<=n){ 
			t++;mi=2e9;
			for(i=t;i<=n;i++){
				ans=0;
				for(j=i-t+1;j<i;j++) ans+=a[i]-a[j],mi=min(mi,ans);
			}
			if(mi>m){cout<<t-1;return 0;}
		}
	}
	else
		for(i=1;i<=n;i++)
			if(i*(i-1)/2*(a[2]-a[1])>m){cout<<i-1;return 0;}
}