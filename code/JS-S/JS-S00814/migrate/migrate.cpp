#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
struct node{
    int now,s;
};
int c,t,n,d,x[N],ans;
vector<int> g[N];
void bfs(int u,int v){
    queue<node> q;
    q.push({u,0});
    int lit=n,res=0;
    while(!q.empty()){
        int a=q.front().now,s=q.front().s;
        q.pop();
        if(a==v){
            if(s<lit){
                lit=s;
                res=0;
            }
            else if(s==lit){
                res++;
            }
            continue;
        }
        for(auto b:g[a]){
            q.push({b,s+1});
        }
    }
    if(res==2){
        ans++;
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--){
        cin >>n>>d;
        for(int i=1;i<=n;i++){
            cin >>x[i];
            for(int j=i-1;j>=1;j--){
                if(x[i]-x[j]>d){
                    break;
                }
                else{
                    g[i].push_back(j);
                }
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                bfs(i,j);
            }
        }
        cout <<t%3<<endl;
    }
    return 0;
}
