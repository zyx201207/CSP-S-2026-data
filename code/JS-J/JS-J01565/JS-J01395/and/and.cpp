#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxa=0,cnt=0,ans=0;
    cin>>n>>m;
    int a[n+5];
    bool flag[n+5];
    memset(flag,1,sizeof(flag));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    while(maxa>0){
        maxa/=2;
        cnt++;
    }
    for(int i=cnt-1;i>=0;i--){
        int x=1<<i,sum=0;
        for(int j=1;j<=n;j++){
            if(flag[j]&&(a[j]&x)>0){
                sum++;
            }
        }
        if(sum>=m){
            ans+=x;
            for(int j=1;j<=n;j++){
                if(flag[j]&&(a[j]&x)==0) flag[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
