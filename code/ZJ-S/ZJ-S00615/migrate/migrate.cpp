#include<bits/stdc++.h>
using namespace std;
long long dis[305][305],cnt[305][305],x[2000005],c,t,d,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(13<=c && c<=14){
		while(t--){
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> x[i];
			}
			long long ans=0;
			for(int i=1;i<n;i++){
				int l=upper_bound(x+1,x+1+n,x[i]+d)-x;
				if(l==n+1)continue;
				l--;
				if(l==i)continue;
				if(l-1==i)continue;
				int r=upper_bound(x+1,x+1+n,x[l-1]+d)-x-1;
				l=max(l,(int)(upper_bound(x+1,x+1+n,x[l-2]+d)-x-1));
				ans+=r-l;
			}
			cout <<ans << endl;
		}
		return 0;
	}
	if(11<=c && c<=12){
		while(t--){
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> x[i];
			}
			long long q=x[2]-x[1];
			long long c=d/q;
			//cout << endl << "xx   "<< n << " " << q << " " << c << endl << endl;
			if(c==0){
				cout << 0 << endl;
			}
			else if(c==1){
				cout << 0 << endl;
			}
			else{
				long long ans=0;
				for(int i=c+1;i<n && i/c<2;i++){
					if(i==c*2-1)ans+=n-i;
				}
				cout << ans << endl;
			}
		}
		return 0;
	}
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					dis[i][j]=dis[i][j]=1;
					cnt[i][j]=cnt[j][i]=1;
				}
			}
		}
		for(int x=1;x<=n;x++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if((i==x || j==x) || i==j)continue;
					if(dis[i][x]+dis[x][j]<dis[i][j]){
						dis[i][j]=dis[i][x]+dis[x][j];
						cnt[i][j]=cnt[i][x]*cnt[x][j];
						cnt[i][j]=min(cnt[i][j],(long long)3);
					}
					else if(dis[i][x]+dis[x][j]==dis[i][j]){
						cnt[i][j]+=cnt[i][x]*cnt[x][j];
						cnt[i][j]=min(3ll,cnt[i][j]);
					}
				}
			}
		}
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					num++;
				}
			}
		}
		cout << num << endl;
	}
	
	
}