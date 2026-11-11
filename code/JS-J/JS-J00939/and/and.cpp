#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll ans;
ll a[N];
void dfs(int k,ll sum,int c){
    if(c==m){
        ans=max(ans,sum);
        return ;
    }
    if(k>n) return;
    dfs(k+1,sum,c);
    if(sum==0){
        dfs(k+1,a[k],c+1);

    }else{
        dfs(k+1,sum&a[k],c+1);
    }
    return;
}
ll maxx=-1;
bool cmp(ll a,ll b){
    return a>b;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int found0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        if(a[i]==0) found0++;
    }
    if(found0>n-m){
        cout<<0;
        return 0;
    }
    if(n<=20){//baoli 25pts;
        dfs(1,0,0);
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }//50pts;
    if(maxx<4){
        int found3=0;
        int found2=0;
        int found1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==3) found3++;
            if(a[i]==3) found3++;
            if(a[i]==3) found3++;
        }
        if(found3>=m) cout<<3;
        else{
            m-=found3;
            if(found2>=m) cout<<2;
            else{
                m-=found2;
                if(found1>=m) cout<<1;
                else{
                    cout<<0;
                }
            }
        }
        return 0;
    }//10pts;
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
    return 0;
}
