#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000006],ff,cnt,m,ans;
map<int,int> tt;
void f(int p,int ii,int sum,int res,int pp){
	if(p>ii){
		if(res<m)m=res,cnt=1;
		else if(res==m && tt[pp]==0)cnt++,tt[pp]=1;
		return ;
	}
	if(p==ii)f(p+1,ii,sum+0,res,pp);
	else if(a[p+1]-a[p]+sum<=d)f(p+1,ii,sum+a[p+1]-a[p],res,pp);
	f(p+1,ii,0,res+1,pp+(1<<p));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ff=0,ans=0;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				ff=1;
				break;
			}
		}
		if(n>=3 && ff==0){
			if(d>a[2]-a[1])cout<<max(n-d/(a[2]-a[1])*2+1,0ll)<<endl;
			else cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>d || a[i-1]>d)continue;
			for(int j=i-2;j>=1;j--){
				if(a[j]>d)break;
				cnt=0,m=2e6;
				tt.clear();
				f(j+1,i,a[j+1]-a[j],1,1<<j);
				ans+=(cnt==2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
