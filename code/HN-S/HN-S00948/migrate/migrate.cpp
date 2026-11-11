#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f;
int c,t,n,d,ans,cnt,mil=INF;
int a[2000005];
void getmin(int st,int et,int cn){
	//cout<<st<<" "<<et<<" "<<cn<<" "<<mil<<endl;
	if(et-st>d || st>et) return ;
	if (st==et){
		mil=min(mil,cn);
		return ;
	}
	for (int i=1;i<=d;i++){
		getmin(st+i,et,cn+1);
	}
	return ;
}
void bfs(int st,int et,int cn){
	if(et-st>d || st>et) return ;
	if (st==et && cn==mil){
		//cout<<st<<" "<<et<<" "<<cn<<" "<<cnt<<endl;
		cnt++;
		return ;
	}
	for (int i=1;i<=d;i++){
		bfs(st+i,et,cn+1);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0,cnt=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				cnt=0;
				mil=INF;
				if (a[j]-a[i]<d) continue;
				getmin(a[i],a[j],0);
				mil+=1;
				bfs(a[i],a[j],0);
				cout<<mil<<endl;
				if (mil==INF) continue;
				if (cnt==2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
