#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int d,x[N],n,minn,cnt=0;
int dis[305][305],cntt[305][305];
void dfs(int cur,int sum,int des){
	if(cur==des){
		if(minn>sum){
			minn=sum;
			cnt=1;
		}
		else if(minn==sum)
			cnt++;
		return;
	}
	for(int i=cur+1;i<=des;i++)
		if(x[i]-x[cur]<=d)
			dfs(i,sum+1,des);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14){
			int sum[N];
			memset(sum,0,sizeof(sum));
			for(int i=1,j=1;j<=n;j++){
				while(x[i]-x[j]<=d&&i<=n)
					i++;
				sum[i]++;
			}
			for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
			for(int i=1;i<=n;i++) if(sum[i]==2) ans++;
			cout<<ans<<endl;
			continue;
		}
		else if(c<=2&&c>0){
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					cnt=0;
					minn=n;
					dfs(i,0,j);
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		else if(c<=6&&c>=3){
			memset(dis,0x3f,sizeof(dis));
			memset(cntt,0x3f,sizeof(cntt));
			for(int i=1;i<=n-1;i++){
				dis[i][i]=0;
				cntt[i][i]=1;
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d) cntt[i][j]=dis[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(k<=i||k>=j) continue;
						if(dis[i][j]>dis[i][k]+dis[k][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
							cntt[i][j]=cntt[i][k]*cntt[k][j];
						}
						else if(dis[i][j]==dis[i][k]+dis[k][j]) cntt[i][j]+=cntt[i][k]*cntt[k][j];
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cntt[i][j]==2&&dis[i][j]<n) ans++;	
				}
			}
			cout<<ans<<endl;
			continue;
		}	
		else if(c==11||c==12){
			if(x[2]-x[1]>d){
				cout<<0<<endl;
				continue;
			}
			int nxt=d/(x[2]-x[1]);
			for(int i=1;i<=n;i++){
				if(i+nxt<=n&&nxt==2) ans++;
				if(i+2*nxt-1<=n) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
