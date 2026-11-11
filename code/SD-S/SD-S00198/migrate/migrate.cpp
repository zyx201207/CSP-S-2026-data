#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,a[2000010];
int b[2000010],x[2000010];
pair<int,pair<int,int> >  q[20010];
int head,tail;
long long dp[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[n+1]=4e18;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			long long x=a[2]-a[1],val=d/x,ans=0;
			for(int i=1;i<=n;i++) ans+=(i+2*val-1<=n&&val>1);
			cout<<ans<<'\n';
			continue;
		}
		if(c==13||c==14){
			int pos=0;
			for(int i=0;i<=n+1;i++) b[i]=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					pos=i;
					break;
				}
			}
			for(int i=pos+1;i<=n;i++){
				int j=upper_bound(a+1,a+n+1,a[i]-d)-a-1;
				x[i]=j;
				b[j]++;
			}
			int p=pos+1;
			long long ans=0;
			for(int i=1;i<pos;i++){
				int j=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				while(p<=j) b[x[p]]--,p++;
				if(j<=n) ans+=b[j-1];
			}
			cout<<ans<<'\n';
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n+1;j++) dp[j]=0;
			head=10000,tail=9999;
			int now=0;
			q[++tail]={i,{0,1}};
			dp[0]=1;
			for(int j=i-1;j;j--){
				while(tail>=head&&a[q[tail].first]-a[j]>d){
					dp[q[tail].second.first]-=q[tail].second.second;
					while(now<=n&&!dp[now]) now++;
					tail--;
				}
				if(head>tail) break;
				ans+=(dp[now]==2);
				q[--head]={j,{now+1,dp[now]}};
				dp[now+1]+=dp[now];
			}
		}
		cout<<ans<<'\n';
	}
}
//RP++
