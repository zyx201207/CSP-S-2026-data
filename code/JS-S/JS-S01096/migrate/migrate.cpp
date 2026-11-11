/*#include<bits/stdc++.h>
#define N 2000001
#define inf 1e18
using namespace std;
int c,t;
int n,d;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    if(c==0){
        cout<<1<<endl;
        cout<<2<<endl;
    }
    while(t--){
        cin>>n>>d;
        int cnt=0;
        vector<vector<int> > edges(n+1,vector<int>(0));
        for(int i=0;i<n;i++){
            cin>>a[i];
            for(int j=i-1;j>=0;j--){
                if(a[i]-a[j]>d)break;
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }i will get csps1
        int ta,lth;
        for(int i=0;i<n;i++){
            queue<pair<int,int> > que;
            vector<long long> v(n,inf);
            vector<int> ct(n,0);
            que.push(make_pair(i,0));
            while(!que.empty()){
                ta=que.front().first;
                lth=que.front().second;
                que.pop();
                if(v[ta]==lth)ct[ta]++;
                else ct[ta]=0,v[ta]=lth;
                for(int j=0;j<edges[ta].size();j++){
                    que.push(make_pair(edges[ta][j],lth+1));
                }
            }
            for(int i=0;i<n;i++)if(ct[i]==2)cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}*/
#include<bits/stdc++.h>
#define N 5001
#define inf 1e18
using namespace std;
int c,t;
int n,d;
long long a[N];
int dp[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int cnt=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[j][k]=0;
            dp[i][0]=1;
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    for(int pst=j-1;a[j]-a[pst]<=d;pst--){
                        dp[j][k]+=dp[pst][k-1];
                    }
                }
            }
            for(int j=i;j<=n;j++){
                for(int k=0;k<=n;k++){
                    if(dp[j][k]){
                        if(dp[j][k]==2)cnt++;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
        /*
        bool flag=true;
        for(int i=2;i<=n;i++)if(a[i]-a[i-1]!=a[2]-a[1])flag=false;
        if(flag){
            if(d<a[2]-a[1]){
                cout<<0<<'\n';
                continue;
            }

        }
        */
    }
    return 0;
}
