#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,res=0,p[5100],x[5100],dis[5100],cnt[5100];
void calc(int l){
	dis[l]=0,cnt[l]=1;
	for(int i=l+1;i<=n;i++){
		dis[i]=INT_MAX,cnt[i]=0;
		for(int j=l;j<i;j++) if(x[i]-x[j]<=d)
			dis[i]=min(dis[i],dis[j]+1);
		if(dis[i]<=1e9) for(int j=l;j<i;j++)
			if(x[i]-x[j]<=d&&dis[i]==dis[j]+1) cnt[i]+=cnt[j];
		res+=cnt[i]==2;
	}
}
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,res=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) calc(i);
		cout<<res<<endl;
	}
	return 0;
}