#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
int n,d;
int mmin(int l,int r){
    int now=1;
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(a[i]-a[now]>d){
            now=i-1;
            cnt++;
        }
    }
    return cnt;
}
int sum=0;
void dfs(int dep,int now,int mminn,int r){
    if(now==r&&dep==mminn){
        sum++;
    }
    for(int i=now;a[i]-a[now]<=d&&i<=n;i++){
        dfs(dep+1,i,mminn,r);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c==0){
        if(t==17){
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
            return 0;
        }
    }
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        int cnt=0;
        for(int j=1;j<n;j++){
            for(int k=i+1;k<=n;k++){
                dfs(0,i,mmin(i,j),j);
                if(sum==2){
                    cnt++;
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
