#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005][105],tr[200005],ls[200005],zh[105];
int n,m,mt;
void sze(int i,int x){
    int w=1,t=0;
    while(w*2<=x){
        w*=2;
        t++;
    }  
    mt=max(mt,t+1);
    while(x!=0){
        if(x>=w){
            x-=w;
            a[i][t+1]+=1;
        }
        t--;
        w/=2;
    }
}
int ezs(){
    int w=1,ans=0;
    for(int i=1;i<=mt;i++){
        ans+=zh[i]*w;
        w*=2;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sze(i,x);
        tr[i]=1;
    }
    for(int j=mt;j>=1;j--){
        memset(ls,0,sizeof(ls));
        int an=0;
        for(int i=1;i<=n;i++){
            if(tr[i]==0){
                continue;
            }
            if(a[i][j]==1){
                an++;
                ls[i]=1;
            }
        }  
        if(an>=m){
            for(int i=1;i<=n;i++){
                if(tr[i]==0){
                    continue;
                }
                if(ls[i]==0){
                    tr[i]=0;
                }
            }
            zh[j]=1;
        }
    }
    cout<<ezs();
    return 0;
}