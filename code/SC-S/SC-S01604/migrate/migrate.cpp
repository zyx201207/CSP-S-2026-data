#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=5050;
int c,T,n,d,arr[N],g[M][M],dis[M][M],s[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>arr[i];
		if(n<=5000){
			for(int i=1;i<=n;i++){
				int now=i;
				for(int j=i+1;j<=n;j++){
					if(arr[j]-arr[i]<=d) dis[i][j]=1;
					else{
						while(now<j&&arr[j]-arr[now]>d) now++;
						dis[i][j]=dis[i][now]+1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				int now=i,r=i+1;
				for(int j=i+1;j<=n;j++){
					if(arr[j]-arr[i]<=d) g[i][j]=1;
					else{
						while(now<j&&arr[j]-arr[now]>d) now++;
						r=max(r,now-1);
						while(r<j&&dis[i][j]==dis[i][r+1]+1) r++;
						g[i][j]=s[i][r]-s[i][now-1];
					}
					s[i][j]=s[i][j-1]+g[i][j];
				}
			}
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(g[i][j]==2){
						res++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++) g[i][j]=s[i][j]=0;
			}
			cout<<res<<'\n';
		}
		else if(c==11||c==12){
			int k=d/(arr[2]-arr[1]);
			if(k==0||k==1) cout<<0<<'\n';
			else cout<<max(0ll,n-(2*k)+1)<<'\n';
		}
		else if(c==13||c==14){
			if(arr[n]-arr[1]<=d) cout<<0<<'\n';
			else{
				int p=0;
				for(int i=1;i<=n;i++){
					if(arr[i]-arr[1]<=d&&arr[n]-arr[i]<=d){
						p=i;
						if(p!=1&&p!=2&&p!=n-1&&p!=n)break;
					}
				}
				arr[0]=arr[1]-1,arr[n+1]=arr[n]+1;
				int l=lower_bound(arr+1,arr+n+1,arr[p+2]-d)-arr-1;
				int r=upper_bound(arr+1,arr+n+1,arr[p-2]+d)-arr;
				int res=0,L=lower_bound(arr+1,arr+n+1,arr[p+1]-d)-arr-1;
				for(int i=1;i<=min(l,L);i++){
					int nowr=upper_bound(arr+1,arr+n+1,arr[p-1]+d)-arr-1;
					res+=max(0ll,nowr-r+1);
				}
				int R=upper_bound(arr+1,arr+n+1,arr[p-1]+d)-arr;
				for(int i=max(r,R);i<=n;i++){
					int nowl=lower_bound(arr+1,arr+n+1,arr[p+1]-d)-arr;
					res+=max(0ll,l-nowl+1);
				}
				cout<<res<<'\n';
				arr[0]=arr[n+1]=0;
			}
		}
	}
	return 0;
}
/*
13 1
15 8
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/