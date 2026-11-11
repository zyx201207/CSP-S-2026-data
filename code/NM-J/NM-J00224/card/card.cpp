#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int arr[N],vis[M],n,m,ans[M],ji[N],idx=1,tv[N];
vector<int>turn[N];
int main(){
    freopen("card.in","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=n;i>=1;i--){
        if(!(vis[arr[i]])){
            turn[i]=turn[i+1];
            turn[i].push_back(arr[i]);
            vis[arr[i]]=i;
            tv[i]=i;
            ji[i]++;
        }else{
            tv[i]=tv[vis[arr[i]]];
            turn[i]=turn[tv[i]];
            ji[tv[i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(ji[i]){
                for(int j=0;j<turn[i].size();j++){
                        ans[turn[i][j]]+=ji[i];
                }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
