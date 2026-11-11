#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],k,s,tl,ts=0,fs,es,f[200005],e[200005];
char c[200005],cf[200005],cd[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];
    }
    k=0;
    for(int i=1;i<=n;i++){
        if(k+a[i]<m/2){
            fs++;
            f[fs]=a[i];
            cf[fs]=c[i];
            k+=a[i];
        }else{
            fs++;
            f[fs]=m/2-k;
            cf[fs]=c[i];
            break;
        }
    }
    k=0;
    for(int i=n;i>=1;i--){
        if(k+a[i]<m/2){
            es++;
            e[es]=a[i];
            cd[es]=c[i];
            k+=a[i];
        }else{
            es++;
            e[es]=m/2-k;
            cd[es]=c[i];
            break;
        }
    }
    tl=1,ts=e[1];
    for(int i=1;i<=fs;i++){
        ll op=0;
        k=f[i];
        while(op+ts<k){
            if(cf[i]!=cd[tl]){
                s+=ts;
            }
            op+=ts;
            tl++;
            ts=e[tl];
        }
        ts-=(k-op);
        if(cf[i]!=cd[tl]){
            s+=(k-op);
        }
        if(ts==0){
            tl++;
            ts=e[tl];
        }
    }cout<<s;
    return 0;
}
