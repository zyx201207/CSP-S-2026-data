#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c,T,d;
int a[2000005];
bool ok(int x,int y){
    int sum=a[x],k[y-x+1],knt=0;
    k[++knt]=x;
    while(sum<a[y]){
        int u=lower_bound(a+x,a+y+1,sum+d)-a;
        u-=((a[u]-sum)>d)?1:0;
        k[++knt]=u;
        if(k[knt-1]==u){return 0;}
        sum=a[u];
    }
    sum=a[y];
    while(sum>a[x]){
        int u=lower_bound(a+x,a+y+1,sum-d)-a;
        if(u!=k[--knt]){return 1;}
        sum=a[u];
    }
    return 0;
}
int bbrute(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            //check if (i,j).
            if(ok(j,i)){
                ans++;
            }
        }
    }
    return ans;
}
void solve(){
    memset(a,0,sizeof a);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<bbrute()<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
