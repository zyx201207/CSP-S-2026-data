#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],ans,vis[200010],del[200010],tong[300010];
bool f;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f=1;
        memset(vis,0,sizeof(vis));
        memset(del,0,sizeof(del));
        vector<int>vec;
        for(int j=i;j<=n;j++){
            if(!vis[j]&&!del[j]){
                vec.push_back(a[j]);
                vis[j]=1;
            }
            else{
                for(int x=0;x<vec.size();x++){
                    if(vec[x]==a[j]&&del[x]!=1){
                        f=1;
                        for(int k=x;k<=vec.size();k++){
                            del[k]=1;
                        }
                        vec.push_back(a[j]);
                        tong[a[j]]++;
                    }
                }
                if(f==0){
                    vec.push_back(a[j]);
                    tong[a[j]]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<' ';
    }
    return 0;
}
