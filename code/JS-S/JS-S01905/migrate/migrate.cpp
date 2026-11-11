#include <bits/stdc++.h>
using namespace std;
const int N=2000002;
const int M=1e9;
int c,T,n,an;
long long d,x[N];
int mp[302][302];
vector<int>mp1[302];
bool bb;
void dfs(int fr,int to,int ls,int t){
    if(t>ls)return;
    if(bb==1||fr>to)return;
    if(fr==to){
        an++;
        if(an>2){
            bb=1;
        }
        return;
    }
    int l=mp1[fr].size();
    for(int i=0;i<l;i++){
        if(bb==1)return;
        dfs(mp1[fr][i],to,ls,t+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    while(T--){
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
            mp[i][j]=M;
        else mp[i][j]=0;
        }
        mp1[i].clear();
        }
        long long bian=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    mp[i][j]=1;
                    mp1[i].push_back(j);
                    bian++;
                }else break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                        if(mp[i][k]!=M&&mp[k][j]!=M)
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
        }
        for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            an=0;
            bb=0;
            dfs(i,j,mp[i][j],0);
            if(an==2)ans++;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
