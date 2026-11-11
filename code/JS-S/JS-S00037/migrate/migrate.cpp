#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2000005;
int x[MAXN];
int di[MAXN];
int c,t;
int n,d;
ll ans;
int num;
int xx;

void dfs(int u,int v,int deep){
    if(u==v && deep==num){
        xx++;
        return;
    }
    for(int i=u+1;i<=v;i++){
        if(x[i]-x[u]<=d){
          dfs(i,v,deep++);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        bool op=true;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>=2){
                di[i]=x[i]-x[i-1];
            }
            if(i>=3){
                if(di[i]!=di[i-1]){
                    op=false;
                }
            }
        }
        if(d>x[n]-x[1]){
            cout<<0<<endl;
            continue;
        }
        if(op==true){
            if(d<di[2]){
                cout<<0<<endl;
                continue;
            }
            else if(d<2*di[2] || d>=3*di[2]){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<n-3<<endl;
                continue;
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                int cur=i;
                num=0;
                xx=0;
                while(cur<j){
                    for(int k=j;k>=i;k--){
                        if(d>x[k]-x[cur]){
                            cur=k;
                            num++;
                            break;
                        }
                    }
                }
                dfs(i,j,0);
                if(xx==2){
                    ans++;
                }

            }
        }
        cout<<ans<<endl;

    }


    return 0;

}
