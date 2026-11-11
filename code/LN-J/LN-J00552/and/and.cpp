#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200001];
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=(2<<m);i++){
        int h=i;
        int cnt=0;
        int vis[200001];
        long long sum=0;
        while(h){
            if(sum==0&&h%2==1)
                sum=h;
            if(h%2==1){
                cnt++;
                vis[h]=1;
            }
            h/=2;
        }
        if(cnt!=m)
            continue;
        for(int i=1;i<=n;i++){
            if(vis[i])
                sum=sum and a[i];
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
