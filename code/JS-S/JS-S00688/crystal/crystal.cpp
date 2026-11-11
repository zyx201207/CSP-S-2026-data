#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt=0,ans=1,l=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<=5000){
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i-1]=a[i]-a[i-1];
    }
    for(int i=1;i<n;i++){
        b[i]+=b[i-1];
    }
    for(int i=2;i<=n;i++){
            cnt=1;
            l=m;
        for(int j=i-1;j>=1;j--){
            if(l<(b[i-1]-b[j-1])){
                ans=max(cnt,ans);
                break;
            }else{
                l-=(b[i-1]-b[j-1]);
                cnt++;
            }
        }
        ans=max(cnt,ans);

    }
    cout<<ans;}
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int h=a[2]-a[1];
        if(h==1){
            for(int i=1;;i++){
                if(i*(i+1)>2*m){
                    cout<<i;
                    return 0;
                }
            }
        }else{
            int u=m/h;
            u*=2;
            for(int i=1;;i++){
                if(i*(i+1)>u){
                    cout<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
