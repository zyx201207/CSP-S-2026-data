#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
const int N=2e5+5;
ll n,m,a[N],ans=0,maxn=0,id=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        maxn=max(maxn,a[i]);
    }
    if(maxn==0){
        cout<<0;
        return 0;
    }
    while(maxn){
        id++;
        maxn/=2;
    }
    id--;
    for(int i=id;i>=0;i--){
        ll cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]>=(1<<i)){//pd id position is 1
                cnt++;
            }
        }
        if(cnt>=m){//delete (1<<id)==0
            ans=ans+(1<<i);
            int tj=0;
            for(int j=1;j<=n;j++){
                if(a[j]>=(1<<i)){
                    tj++;
                    a[tj]=a[j];
                }
            }
            n=tj;
        }
        //delete change (1<<id) to 0
            for(int j=1;j<=n;j++){
                if(a[j]>=(1<<i)){
                    a[j]-=(1<<i);
                }
            }
    }
    cout<<ans;
    return 0;
}

