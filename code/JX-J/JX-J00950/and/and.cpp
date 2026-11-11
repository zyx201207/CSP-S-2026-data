#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],ans[1000001],mj=-1000001,pd,maxn=-10000001,sum,maxm=-10000001;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            sum=a[i];
        }
        else{
            sum&=a[i];
        }
        ans[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++){
        if(ans[a[i]]==m&&a[i]>mj){
            mj=a[i];
            pd=1;
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxm=max(maxm,a[i]&a[j]);
            }
        }
        cout<<maxm;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(pd){
        cout<<mj;
    }
    return 0;
}
