#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],q[500005],l[500005],u[500005],ans[300005],qw[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        cin>>a[x-i+1];
    }
    for(int i=1;i<=x;i++){
        u[i]=1;
        if(q[a[i]]!=0){
            l[i]=q[a[i]];
            q[a[i]]=i;
        }else{
            qw[i]=1;
            q[a[i]]=i;
            l[i]=i-1;
        }
    }
    for(int i=x;i>=1;i--){
        if(qw[i]){
            ans[a[i]]+=u[i];
        }
        u[l[i]]+=u[i];
    }
    for(int i=1;i<=y;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
