#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int b[N][35];
int t[35];
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int maxn=0;
    for(int i=1;i<=n;i++){
        int x=a[i];
        int cnt=0;
        while(x){
            cnt++;
            if(x&1) b[i][cnt]=1,t[cnt]++;
            maxn=max(maxn,cnt);
            x>>=1;
        }
    }
    int ans=0;
    for(int i=maxn;i>=1;i--){
        if(t[i]>=m){
            ans|=(1<<(i-1));
            for(int j=1;j<=n;j++){
                if(b[j][i]==0&&!vis[j]){
                    vis[j]=true;
                    for(int k=1;k<=maxn;k++)
                        if(b[j][k]==1)
                            t[k]--;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
4 2
3 15 12 12
*/
