#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[200005];
vector<int>s;
int dis[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    for(int t=1;t<=m;t++){
        memset(ans,sizeof(ans),0);
        memset(dis,sizeof(dis),0);
        s.clear();
        for(int i=t;i<=n;i++){
            if(dis[a[i]]==0){
                dis[a[i]]=1;
                s.push_back(a[i]);
            }
            else{
                dis[a[i]]=1;
                for(int j=s.size()-1;j>=0;j--){
                    dis[a[j]]=0;
                    if(a[i]==a[j])break;
                }
                s.clear();
                s.push_back(a[i]);
            }
            for(auto j:s){
                if(j==a[i]){
                    ans[j]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
