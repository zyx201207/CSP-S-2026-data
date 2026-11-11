#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],mx,s7;
struct node{
    int number,i,step;
};
signed main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[mx]) mx=i;
        if(i==1) s7=a[i];
        s7&=a[i];
    }
    if(m==1) cout<<a[mx];
    else if(m==n) cout<<s7;
    else if(m==2){
        int s8_10=a[1]&a[2];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                s8_10=max(s8_10,a[i]&a[j]);
            }
        }
        cout<<s8_10;
    }else{
        int ans=INT_MIN;
        queue<node> q;\
        for(int i=1;i<=n;i++) q.push({a[i],1,1});
        while(q.size()){
            auto node=q.front();q.pop();
            int number=node.number;int i=node.i;
            int step=node.step;
            if(step==m) ans=max(ans,number);
            else for(int j=i+1;j<=n;j++) q.push({number&a[j],j,step+1});
        }
        cout<<ans;
    }
    return 0;
}
