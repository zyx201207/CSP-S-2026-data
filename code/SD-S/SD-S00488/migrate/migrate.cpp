#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sw,q,n,d,x,y,z,ans,h;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>sw>>q;
	while(q--){
		scanf("%lld%lld",&n,&d);
		scanf("%lld%lld",&x,&y);
		y-=x;
		if(d<y||d/y==1||d/y>=n){
		   	cout<<0<<endl;
		   	continue;
		}
		d/=y;
		for(int i=1;i<min(d,n-d);i++){
			ans+=(n-i-1-i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
