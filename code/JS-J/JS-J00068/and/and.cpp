#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>=b;
}
int n,m,a[200010];
int ans=-1<<30;
int num[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int mask=0;mask<(1<<n);mask++){
            int cnt=0;
            int rear=0;
            int now=(1<<29)-1;
            for(int i=0;i<n;i++){
                if((mask&(1<<i))){
                    cnt++;
                    num[++rear]=a[i+1];
                    now=now&num[rear];
                }
            }
            if(cnt!=m){
                continue;
            }
            ans=max(ans,now);
        }
        cout<<ans;

    }else{
        if(n<=2000){
            if(m==1){
                for(int i=1;i<=n;i++){
                    ans=max(ans,a[i]);
                }
                cout<<ans;
            }
            if(m==n){
                int now=1;
                for(int i=1;i<=n;i++){
                    now=now&a[i];
                }
                cout<<now;
            }
            if(m==2){
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        ans=max(ans,a[i]&a[j]);
                    }
                }
            }
        }else{
            sort(a+1,a+n+1,cmp);
            cout<<a[m];
        }
    }
    return 0;

}
