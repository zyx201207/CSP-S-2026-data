#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000020;
int x[N],dis[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t,cnt1=0;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;cnt1=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++){
			dis[i]=0,cnt[i]=1;
			for(int j=i+1;j<=n;j++){
				dis[j]=n+10,cnt[j]=0;
				int st=lower_bound(x+i,x+j+1,x[j]-d)-x;
				if(cnt[st]>2) break;
				for(int k=st;k<=j-1;k++){
					cnt1++;
					if(dis[k]+1<dis[j]) dis[j]=dis[k]+1,cnt[j]=cnt[k];
					else if(dis[k]+1==dis[j]) cnt[j]+=cnt[k];
					else break;
					if(cnt[j]>2) break;
				}
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//16:30 finish 24pts
//17:01 finish 40pts
//lsy give me luck to get 40pts