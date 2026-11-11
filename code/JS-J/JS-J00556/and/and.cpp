#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,s=1,mi=INT_MAX,b[4];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2!=0)f=0;
        if(a[i]<=3)b[a[i]]++;
        s=s&a[i];
        mx=max(a[i],mx);
        mi=min(a[i],mi);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        cout<<s;
        return 0;
    }
    s=1;
    mx=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(i!=j){
                    mx=max(mx,a[i]&a[j]);
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(f){
        cout<<mi;
        return 0;
    }
    if(b[3]>=m){
        cout<<3;
        return 0;
    }
    if(b[2]+b[3]>=m){
        cout<<2;
        return 0;
    }
    if(b[3]+b[1]>=m){
        cout<<1;
        return 0;
    }
    cout<<0;
return 0;
}
