#include<bits/stdc++.h>
using namespace std;
long long m,n;
int a[500010],b[500010],p=1,q=1,k,s,maxn,len,cnt,he,c;
int sum(int x,int y){
    int z=y-x+1;
    for(int i=1;i<=z;i++){
            s=s+i*b[q+i-2];
    }
    return s;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
    cout<<1;
    return 0;
}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        he+=a[i];
    }
    c=n*a[n]-he;
    if(m>=c){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
    }
    while(p<=n-1){
            len=0;
        if(b[p]>m){
            p++;
            q++;
        }
        q++;
        k=sum(p,q);
        if(k>m){
            p++;
            q=p;
            continue;
        }
        else{
        len=q-p+2;
        for(int i=1;i<=n-1;i++){
            if(a[i]==a[q+1]){
                cnt++;
            }
        }
        len=len+cnt-1;
        if(len>maxn){
            maxn=len;
            }
        }
    }
    cout<<maxn;
    return 0;
}
