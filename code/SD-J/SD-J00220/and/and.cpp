#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,maxx=-1e18;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}else if(m==n){
		maxx=(1<<n)-1;
		for(int i=1;i<=n;i++)maxx&=a[i];
		cout<<maxx;
		return 0;
	}for(int i=1;i<(1<<n);i++){
		int b[35]={0},t=i,B=0,ans=(1<<n)-1,f=0;
		while(t){
			b[++B]=(t&1);
			f+=b[B];
			t>>=1;
		}if(f!=m)continue;
		for(int j=1;j<=B;j++){
			if(b[j])ans&=a[j];
		}maxx=max(maxx,ans);
	}cout<<maxx;
	return 0;
}
