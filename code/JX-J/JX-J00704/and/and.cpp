#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],ton[10];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxxx=max(maxxx,a[i]);
    }
    if(n<=20){
        int sum=0;
        for(int i=1;i<(1<<n);i++){
            int ans=0,cnt=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    if(cnt==0)ans=a[j+1];
                    else ans&=a[j+1];
                    cnt++;
                }
            }
            if(cnt==m)sum=max(sum,ans);
        }
        cout<<sum;
        return 0;
    }
    if(m==1){
        int maxx=0;
        for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(maxxx<4){
        for(int i=1;i<=n;i++){
            ton[a[i]]++;
        }
        if(ton[4]>=m){
            cout<<4;
        }
        else if(ton[3]>=m){
            cout<<3;
        }
        else if(ton[2]+ton[3]>=m){
            cout<<2;
        }
        else if(ton[1]+ton[3]>=m){
            cout<<1;
        }else cout<<0;
        return 0;
    }
    if(n>2000){

            return 0;
    }
    return 0;
}
