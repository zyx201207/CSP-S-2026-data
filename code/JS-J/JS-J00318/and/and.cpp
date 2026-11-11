# include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxn;
long long ans;
//int dp[2005][2005],l[30],w;
int l[30],w;//w shuwei
int s[200005][31],c1[31];
vector <int> r[31];
vector<int>u;
bool vis[200005],f,vis2[200005];
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
    }
    l[0]=1;
    for(int i=1;i<=30;i++){
        l[i]=l[i-1]*2;
    }
    for(int i=1;i<=30;i++){
        if(maxn>=l[i-1]&&maxn<l[i]){
            w=i;
            break;
        }
    }
    /*
    for(int i=1;i<=n;i++)dp[i][1]=max(a[i],dp[i-1][1]);
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {

            dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
        }
    }
    cout<<dp[n][m];*/

    for(int i=1;i<=n;i++)
    {
        for(int j=w-1;j>=0;j--)
        {
            int t=(a[i]>>j)%2;
            //a[i][w-i]=t;
            if(t==1)r[w-j].push_back(i);
        }
    }
    for(int i=1;i<=w;i++)
    {
        if(r[i].size()<m)continue;
        if(f==false){
            u.push_back(i);
            for(auto v:r[i]){
                vis[v]=true;
            }
            f=true;
        }
        else {
            int op=r[i].size();
            for(auto v:r[i]){
                if(vis[v]!=true){
                        op--;
                        //vis2[v]=true;
                }
                else vis2[v]=true;
            }
            if(op>=m){
                u.push_back(i);
                for(int i=1;i<=n;i++)
                {
                    if(vis[i]==true&&vis2[i]!=true)vis[i]=false;

                }
            }
            memset(vis2,false,sizeof(vis2));
        }
    }
    for(auto c:u){
        ans+=l[w-c];
    }
    cout<<ans;
    return 0;
}
