#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N];
int to[N];
stack<int> s;
struct zt{
    int z;
    int x;
}vis[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            vis[k].z=0;
        }
        int siz=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]].z==1){
                int b=siz-vis[a[j]].x;
                siz-=b;
                for(int i=1;i<=b;i++){
                    int c=s.top();
                    vis[c].z=0;
                    s.pop();
                }
            }else{
                siz++;
                s.push(a[j]);
                vis[a[j]].z=1;
                vis[a[j]].x=siz;
            }
        }

        while(!s.empty()){
            int b=s.top();
            to[b]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<to[i]<<' ';
    }
    return 0;
}

