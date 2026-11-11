#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		int f=d/(x[n]=x[n-1]);
		for(int i=2;i*f<=n;i++)ans+=n-i*f;
		cout<<ans<<endl;
	}
	return 0;
}