#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
const ll inf=1e9;
int c,T;
ll n,d,x[N],dis[N][N],cnt[N][N];
bool vis[N];
vector<int> vec[N];
void bfs(int s)
{
    queue<int> q;
    dis[s][s]=0;
    cnt[s][s]=1;
    q.push(s);
    for(int i=1;i<=n;i++) vis[i]=false;
    while(q.size())
    {
        int t=q.front();q.pop();
        if(vis[t]) continue;
        vis[t]=true;
        for(auto i:vec[t]){
            if(dis[s][i]>dis[s][t]+1){
                dis[s][i]=dis[s][t]+1;
                cnt[s][i]=cnt[s][t];
                q.push(i);
            }
            else{
                if(dis[s][i]==dis[s][t]+1){
                    cnt[s][i]+=cnt[s][t];
                    //q.push(i);
                }
            }
        }
        
    }
}
void work2()
{
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=dis[j][i]=inf;
                cnt[i][j]=cnt[j][i]=0;
            }
    }
	for(int i=1;i<=n;i++) vec[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d){
				vec[i].push_back(j);
				//vec[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<cnt[i][j]<<" ";
		}
		//cout<<"\n";
	}
    int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n>5000){
			cout<<0<<"\n";
			continue;
		}
        if(n>300)
        {
			work2();
			continue;
		}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=dis[j][i]=inf;
                cnt[i][j]=cnt[j][i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dis[i][j]=dis[j][i]=0;
                    cnt[i][i]=0;
                    continue;
                }
                if(abs(x[i]-x[j])<=d){
                    dis[i][j]=dis[j][i]=1;
                    cnt[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
					if(i==j) continue;
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                    else{
                        if(dis[i][j]==dis[i][k]+dis[k][j]){
                            cnt[i][j]+=cnt[i][k]*cnt[k][j];
                        }
                    }
                    dis[j][i]=dis[i][j];
                    //cnt[j][i]=cnt[i][j];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
