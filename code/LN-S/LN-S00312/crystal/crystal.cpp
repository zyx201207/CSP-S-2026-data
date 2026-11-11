#include<bits/stdc++.h>
using namespace std;
long long aa=0,bb=1;
long long mmm[200000];
bool cmp(int x,int y){
    return x<y;
}
bool cmpp(int x,int y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,k;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }

    long long a[n+100];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        for(long long i=1;i<=n;i++){
            mmm[a[i]+100000]++;
        }
        long long kl=0;
        for(int i=1;i<=200000;i++){
            kl=max(kl,mmm[i]);
        }
        cout<<kl;
        return 0;
    }
    if(n==2){
        if(m>=(max(a[1]-a[2],a[2]-a[1]))){
            cout<<2;
            return 0;
        }else{
            cout<<1;
            return 0;
        }
    }
    long long ppp=a[2]-a[1];
    long long yyy=0;
    for(long long i=2;i<=n;i++){
        if(ppp!=a[i]-a[i-1]){
            yyy=1;
            break;
        }
    }
    if(yyy==0){
        sort(a+1,a+n+1,cmp);
        if(ppp<0){
            ppp=-ppp;
        }
        while(m>aa){
            aa+=bb*ppp;
            bb++;
        }
        if(m==aa){
            if(bb>=n){
                cout<<n;
            }else{
                cout<<bb;
            }
        }else{
            if((bb-1)>=n){
                cout<<n;
            }else{
                cout<<bb-1;
            }
        }
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    long long sum=0;
    for(long long i=1;i<=n-1;i++){
        sum+=a[n]-a[i];
    }
    if(m>=sum){
        cout<<n;
        return 0;
    }
    long long ans[n+100],daijia=0;
    for(long long i=2;i<=n;i++){
        ans[i]=daijia+(i-1)*(a[i]-a[i-1]);
        daijia=ans[i];
    }
    for(long long i=n;i>=2;i--){
        if(m>=ans[i]){
            cout<<i;
            return 0;
        }
    }
    for(long long i=1;i<=n;i++){
        mmm[a[i]+100000]++;
    }
    long long kl=0;
    for(int i=1;i<=200000;i++){
        kl=max(kl,mmm[i]);
    }
    cout<<kl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
