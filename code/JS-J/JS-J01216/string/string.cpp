#include<bits/stdc++.h>
using namespace std;
long long p[200005];
char l[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,anm=0;
    cin>>n;
    long long k=n;
    for(long long i=1;i<=n;i++){
        cin>>p[i]>>l[i];
    }
    for(long long i=1;i<=n;){
        if(i>=n) break;
        if(p[i]==0){
            i++;
            continue;
        }
        if(p[n]==0){
            n--;
            continue;
        }
        if(l[i]!=l[n]){
            anm=anm+min(p[i],p[n]);
        }
        long long y=min(p[i],p[n]);
        p[i]=p[i]-y;
        p[n]=p[n]-y;

    }
    cout<<anm;
    return 0;
}
