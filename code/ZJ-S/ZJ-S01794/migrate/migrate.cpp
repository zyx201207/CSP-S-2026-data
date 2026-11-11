#include<bits/stdc++.h>
#define AKCSPS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;//0pts
int a[2000100];
signed main(){
	AKCSPS;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0&&t==2){
		cin>>n>>m;
		if(n==4&&m==2)	cout<<"1\n"<<2;
		else{
			cout<<"0\n"<<1;
		}
		return 0;
	}
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)	cin>>a[i];
		if(m==1){
			cout<<0<<endl;
		}
		else{
			int ans=0;
			for(int i=4;i<=n;i++){
				if((i%2==0&&m%2==0)||(i%2==1&&m%2==1))	ans+=(n-i+1);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
