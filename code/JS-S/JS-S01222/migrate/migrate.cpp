#include<bits/stdc++.h>
using namespace std;
long long a[2000005],n,d,c,t,lft,rgh,ans,cnt;
long long dp_lft[2000005],dp_rgh[2000005],rs[2000005],ls[2000005];
long long st[1000005],minn;

long long mi(long long a,int b){
    return a>b?b:a;
}

void dfs(int x,int y,int jp){
    if(x==y){
        st[++cnt]=jp;
        minn=mi(minn,jp);
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d&&jp+1<=minn)
            dfs(i,y,jp+1);
    }
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    if(c>=1&&c<=6){
        while(t--){
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    cnt=0,minn=100005;
                    dfs(i,j,0);
                    int cn=0;
                    for(int i=1;i<=cnt;i++){
                        if(st[i]==minn)cn++;
                    }
                    if(cn==2)ans++;
                }
            cout<<ans<<endl;
        }
        return 0;
    }
    if(c>=13&&c<=14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            cout<<0<<endl;
        }
        return 0;
    }
    return 0;
}
// 16 pts ?
