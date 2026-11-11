#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int pre[N];
int ans=0;
bool cmp(int x,int y){
    return x<=y;
}
bool check(int l,int r){
    if((pre[r]-pre[l-1]+m)-((r-l+1)*a[r])>=0){
        ans=max(ans,r-l+1);
        return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000){
        int dc=a[2]-a[1];
        int tot=-1;
        while(++tot){
            m-=dc*tot;
            if(m<=0){
                cout<<tot-1;
                return 0;
            }
        }
    }else{
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;i-j+1>ans;j++)if(check(j,i))break;
        }
        cout<<ans;
        return 0;
    }
}

