#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],rt[5005][5005],minrt[5005][5005];
void dfs(long long st,long long step,long long lenth,long long usedd){
	if(lenth+1<minrt[st][step]){
		minrt[st][step]=lenth+1;
		rt[st][step]=1;
//		cerr<<"upd "<<st<<' '<<step<<" min="<<lenth+1<<endl; 
	}
	else if(lenth+1==minrt[st][step]){
		++rt[st][step];
//		cerr<<"add "<<st<<' '<<step<<" cnt="<<rt[st][step]<<endl; 
	}
	if(step==n)	return;
//	cerr<<"checking "<<st<<' '<<step<<' '<<lenth<<' '<<usedd<<endl;
	if(usedd!=0&&(a[step+1]-a[step])<=d)
		dfs(st,step+1,lenth+1,a[step+1]-a[step]);
	if(usedd+(a[step+1]-a[step])<=d)
		dfs(st,step+1,lenth,a[step+1]-a[step]+usedd);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(rt,0,sizeof(rt));
		memset(minrt,0x3f,sizeof(minrt));
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<n;++i)
			dfs(i,i,0,0); 
		long long ans=0;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				if(rt[i][j]==2)
					++ans;
		cout<<ans<<"\n";
	}
	return 0;
}
