#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[25][25],ret,ma,op=(1<<30)-1,t1,t2,t3;
void dfs(int dep,int num,int ans){
    if(ans<dp[dep][num]) return;
    if(num==m){
        ret=max(ret,ans);
        dp[dep][num]=ans;
        return;
    }
    for(int i=dep;i+m-num<=n;i++)
        dfs(i+1,num+1,(ans&a[i]));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ma=max(a[i],ma);
        op&=a[i];
        if(a[i]%4>1&&a[i]%2) t1++;
        if(a[i]%4>1) t2++;
        if(a[i]%2) t3++;
    }
    if(n<=20){
        dfs(0,0,(1<<30)-1);
        cout<<ret;
    }
    else {
        if(m==1) cout<<ma;
        else if(m==n) cout<<op;
        else if(m==2){
            int t=0;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    t=max(t,(a[i]&a[j]));
                }
            }
            cout<<t;
        }
        else if(m==n-1){
            cout<<op;
        }
        else if(ma<4){
            if(t1>=m) cout<<3;
            else if(t2>=m) cout<<2;
            else if(t1>=m) cout<<1;
            else cout<<0;
        }
        else{
            sort(a,a+n);
            cout<<a[n-m];
        }
    }
    return 0;
}
