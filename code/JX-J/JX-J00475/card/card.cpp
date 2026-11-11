#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+3,M=3e3+3;
int a[N],num[M];
int n,m;bool v=false,vis[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1])v=true;
        else v=false;
    }
    if(v){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            num[a[j]]++;
            if(vis[a[j]]==true){
                int qq=j-1;
                while(a[qq]!=a[j]){
                    num[a[qq--]]--;
                    if(a[qq]==a[j])break;

                }
                num[a[qq]]--;
                vis[a[qq]]=false;
            }
            vis[a[j]]=true;
        }
        for(int j=1;j<=n;j++)vis[a[j]]=false;
    }
    for(int i=1;i<=m;i++)cout<<num[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
