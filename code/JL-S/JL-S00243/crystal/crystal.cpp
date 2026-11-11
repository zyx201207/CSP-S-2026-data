#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",std);
    freopen("crystal.out","w",std);
    int n,m,a[500001],b[500001],sum=0,p,t,r=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            r=1;
        }
    }
    sort(a+1,a+n+1);
    if(r==0){
        t=1;
        for(int i=1;i<=n;i++){
            sum+=t;
            t++;
            if(sum>m){
                cout<<t-1;
                retrun 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>i) b[j]=a[j]-a[i];
            else b[j]=a[i]-a[j];
        }
        sort(b+1,b+n+1);
        sum=0;
        t=0;
        for(int j=1;j<=n;j++){
            sum+=b[j];
            t++;
            if(sum>m){
                break;
            }
            if(t>=p){
                p=t;
            }
        }
    }
    cout<<p;
    return 0;
}
