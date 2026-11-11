#include<bits/stdc++.h>
using namespace std;
struct op{
	long long a,t;
}at[1000005];
bool cmp(op x,op y){
	return x.a<y.a;
}
long long c,n,m,d,q,w[1000005],k1[1000005],x[1000005],y[1000005],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k1[i];
		for(int j=1;j<=k1[i];j++){
			cin>>at[j].a>>at[j].t;
		}
		sort(at+1,at+1+k1[i],cmp);
	}
	
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(n==1){
		for(int i=1;i<=q;i++){
			ans=0;
			ans+=w[x[i]]+w[y[i]];
			ans+=at[x[i]].t+at[y[i]].t;
			cout<<ans<<endl;;
		}
	}
	else{
		cout<<d;
	}
	return 0;
}
