#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,minn=INT_MAX;
long long d,x[N],ans,cnt;
void dfs(int now,int fi,int tot){
//	cout<<now<<' '<<fi<<' '<<tot<<endl;
	if (now==fi){
//		cout<<minn<<' '<<cnt<<' '<<tot<<endl;
		if(minn==tot)
			cnt++;
		else if (minn>tot){
			minn=tot;
			cnt=1;
		}
		return ;
	}
	for (int i=now+1;i<=fi;i++)
		if (d>=x[i]-x[now])
			dfs(i,fi,tot+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>x[i];
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				cnt=0,minn=INT_MAX;
				dfs(i,j,0);
				if (cnt==2)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
