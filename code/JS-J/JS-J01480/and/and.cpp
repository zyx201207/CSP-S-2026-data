#include<bits/stdc++.h>
using namespace std;
bool er[200005][33];
long long a[200005];
bool vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int minn=31;
    for(int i=1;i<=n;i++){
        vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int wei=30;
        while(x>0){
            er[i][wei]=x%2;
            x/=2;
            wei--;
            if(x==0){
                minn=min(minn,wei);
            }
        }
    }
    for(int j=minn;j<=30;j++){
        int good=0;
        for(int i=1;i<=n;i++){
            if(er[i][j]==1&&vis[i]==1){
                good++;
            }
        }
        if(good<m){
            for(int i=1;i<=n;i++){
                er[i][j]=0;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(er[i][j]==0){
                    vis[i]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        a[i]=0;
        long long p=1;
        for(int j=30;j>=minn;j--){
            a[i]+=p*er[i][j];
            p*=2;
        }
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
