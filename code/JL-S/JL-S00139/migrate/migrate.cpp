#include<bits/stdc++.h>

using namespace std;
int c,t;
long long  arr[10000000];
int lx[1005][1005];
int n,d;
int w[1005][1005];
void xl(int x){
    if(x>n)return;
    for(int i=x+1;i<=n;i++){
        if(arr[i]-arr[x]<=d){
            lx[x][i]=i;
            xl(i);
        }
    }
}


void xl2(int x,int cnt){
    if(x>n)return;
    for(int i=x+1;i<=n;i++){
        if(lx[x][i]!=0){
            w[i][cnt]++;
            xl2(i,cnt+1);
        }
    }
}



int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        long long  minn=1e18;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            minn=min(minn,arr[i]);
        }if(minn<0){
            for(int i=1;i<=n;i++){
                arr[i]-=minn;
            }
        }
        xl(1);
        xl2(1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(w[i][j]==2)ans++;

            }
        }cout<<ans<<endl;

    }
    return 0;
}
