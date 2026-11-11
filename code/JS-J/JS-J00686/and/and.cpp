#include<bits/stdc++.h>
using namespace std;
bool num[200005][32],u[200005],ans[32];
int p(int x){
    int a=1;
    x--;
    while(x--){
        a*=2;
    }
    return a;
}
int n,m,coutans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=32;j++){
            num[i][j]=x%2;
            x/=2;
        }
    }
    for(int i=1;i<=n;i++){
        u[i]=1;
    }
    for(int i=1;i<=31;i++){
        ans[i]=0;
    }
    for(int i=32;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(num[j][i] && u[j]){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(!num[j][i]){
                    u[j]=0;
                }
            }
            ans[i]=1;
        }
    }
    for(int i=1;i<=31;i++){
        if(ans[i]){
            coutans+=p(i);
        }

    }
    cout<<coutans;
    return 0;
}
