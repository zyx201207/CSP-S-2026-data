#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ma,mma,t,k,f,f1,mi=1e9,ff;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=ma){
            k=i;
            ma=a[i];
        }

        mi=min(mi,a[i]);
    }

    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            if(i!=k){
                t=ma&i;
                mma=max(mma,t);
            }
        }
        cout<<mma;
        return 0;
    }
    if(m==n){
        t=a[1];
        for(int i=2;i<=n;i++){
            t=a[i]&t;
        }
        cout<<t;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1){

        }
    }

    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            f=1;
        }if(a[i]>=4){
            f1=1;
        }if(a[i]==2){
            ff=1;
        }
    }
    if(f1==0){
        if(mi==3) cout<<3;
        if(mi==2) cout<<2;
        if(mi==1){
            if(ff==0){
                cout<<0;
            }else cout<<1;
        }
        return 0;
    }
    if(f==0){
        cout<<n-m;
        return 0;
    }
    sort(a+1,a+n+1);
    int c=1;
    for(int i=n;c<=m;i--){

        t=a[i]&t;
        c++;

    }
    cout<<t;
    cout<<endl;
    return 0;
}
