#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=5e3+5;
const int M=2e6+6;
const int inf=1e18;
int C,T;
int n,d,a[M],dis[N],ans;
int cnt[M],c[M];
int nxt[M];
void subtask_1(){
	for(int i=1;i<=n;i++){
		dis[i]=0,cnt[i]=1;
		for(int j=i+1;j<=nxt[i];j++)cnt[j]=1,dis[j]=1,c[j]=0;
		for(int j=nxt[i]+1;j<=n;j++)cnt[j]=c[j]=0,dis[j]=inf;
		int r=nxt[i];
		int lst=nxt[i];
		for(int j=i+1;j<=n;j++){
			if(dis[j]==inf)break;
			c[j]+=c[j-1];cnt[j]+=c[j];
			if(dis[j]!=dis[j-1]){
				lst=nxt[j-1];
				for(int k=r+1;k<=nxt[j];k++)dis[k]=dis[j]+1;
				r=nxt[j];c[nxt[j-1]+1]+=cnt[j];c[nxt[j]+1]-=cnt[j];
			}
			else{
				c[lst+1]+=cnt[j];c[nxt[j]+1]-=cnt[j];
				for(int k=r+1;k<=nxt[j];k++)dis[k]=dis[j]+1;
				r=nxt[j];
			}
		}
		for(int j=i+1;j<=n;j++)if(cnt[j]==2)++ans;
	}
	cout<<ans<<endl;
}
int len[M];
void GO(){
	int i=1;
	dis[i]=0,cnt[i]=1;
	for(int j=i+1;j<=nxt[i];j++)cnt[j]=1,dis[j]=1,c[j]=0;
	for(int j=nxt[i]+1;j<=n;j++)cnt[j]=c[j]=0,dis[j]=inf;
	int r=nxt[i];
	int lst=nxt[i];
	for(int j=i+1;j<=n;j++){
		if(dis[j]==inf)break;
		c[j]+=c[j-1];cnt[j]+=c[j];
		if(dis[j]!=dis[j-1]){
			lst=nxt[j-1];
			for(int k=r+1;k<=nxt[j];k++)dis[k]=dis[j]+1;
			r=nxt[j];c[nxt[j-1]+1]+=cnt[j];c[nxt[j]+1]-=cnt[j];
		}
		else{
			c[lst+1]+=cnt[j];c[nxt[j]+1]-=cnt[j];
			for(int k=r+1;k<=nxt[j];k++)dis[k]=dis[j]+1;
			r=nxt[j];
		}
	}
	for(int j=1;j<=n;j++)if(cnt[j]==2)len[j-i+1]++;
	for(int j=1;j<=n;j++)ans+=len[j]*(n-j+1),len[j]=0;
	cout<<ans<<endl;
}
signed main(){
	O1145 O1919
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){cout<<0<<endl;continue;}
		int cc=a[2]-a[1];
		bool subtask_2=true;
		for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=cc){subtask_2=false;break;}
		for(int i=1;i<=n;i++){
			nxt[i]=max(nxt[i-1],i);
			for(int j=nxt[i]+1;j<=n;j++)if((a[j]-a[i])<=d)nxt[i]=j;else break;
		}
		int find=0;
		for(int i=1;i<=n;i++)if(a[i]-a[1]<=d&&a[n]-a[i]<=d){find=i;break;}
		if(n<=5000){subtask_1();continue;}
		if(subtask_2){GO();continue;}//A
		if(find!=0){//B
			for(int i=1;i<=n;i++){
				int s=nxt[i];
				ans+=n-nxt[s-1];
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
