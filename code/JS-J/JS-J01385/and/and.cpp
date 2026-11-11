#include<iostream>
#include<cmath>
using namespace std;
int n,m,mx=-1;
bool a[200010][40];
bool vis[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        for(int j=1;x!=0;x/=2,j++){
            a[i][j]=x%2;
            mx=max(mx,j);
        }
    }
    long long ans=0;
    for(int j=mx;j>=1;j--){
        ans*=2;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i][j]==1&&vis[i]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int i=1;i<=n;i++){
                if(a[i][j]==0){
                    vis[i]=0;
                }
            }
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
