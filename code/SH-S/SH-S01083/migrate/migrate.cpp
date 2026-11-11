#include<bits/stdc++.h>
using namespace std;
int n,d,t,c,x,a,b;
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(i==1)b=a;
			if(i==2)b=a-b;
		}
		x=d/b;
		ans=0;
		for(int i=x+2;i<=n;i++){
			if((i-1)%x==0)continue;
			ans+=n-i+1;
		}
		cout<<ans<<'\n';
	}
}
