#include<bits/stdc++.h>;
using namespace std;
typedef long long ll;
const int N = 5e5+10;
const int N2= 2e5+10;
int n,m;
int a[N];
int ans[N2];
//map<int,vector<int>> mp;
bool vis[N2];
int main(){
    freopen("card1.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //mp[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            ans[a[i]]++;
            break;
        }
        memset(vis,0,sizeof(vis));
        int pos;
        for(int j=n;j>=i;j--){
            if(vis[a[j]]){
                pos=j+1;
                break;
            }
            vis[a[j]]=1;
        }
        for(int j=pos;j<=n;j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }



    return 0;
}
