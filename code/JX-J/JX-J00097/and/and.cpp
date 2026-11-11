#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum;
bool f=1;
bool f2=1;
bool f3=1;
int h[10];
void dfs(int k,long long ans,int t){
    if(n-k+1+t<m){
        return;
    }
    if(t==m){
        sum=max(sum,ans);
        return;
    }
    if(k>n){
        return;
    }
    if(t==0){
        dfs(k+1,a[k],t+1);
    }
    else{
        dfs(k+1,ans&a[k],t+1);
    }
    dfs(k+1,ans,t);
}
bool bf(long long x){
    x++;
    while(x){
        if(x&1==1 && x>1){
            return 0;
        }
        x=x>>1;
    }
    return 1;
}
int g(long long x){
    int l=0;
    while(x){
        if(x&1==1){
            l++;
        }
        x>>1;
    }
    return l;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(f){
            f=bf(a[i]);
        }
        if(a[i]!=i-1){
            f2=0;
        }
        if(a[i]>=4){
            f3=0;
        }
    }
    if(f){
        sort(a+1,a+1+n);
        cout<<a[n+1-m];
        return 0;
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<sum;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            sum=max(sum,a[i]);
        }
        cout<<sum;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    sum=max(sum,(a[i]&a[j]));
                }
            }
        }
        cout<<sum;
        return 0;
    }
    if(n==m){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(f2 && bf(n-1)){
        if(m==n-1){
            cout<<0;
            return 0;
        }
        cout<<n-m;
        return 0;
    }
    if(f3){
        for(int i=1;i<=n;i++){
            h[a[i]]++;
        }
        if(h[3]>=m){
            cout<<3;
        }
        else if(h[2]>=m){
            cout<<2;
        }
        else if(h[1]+h[3]>=m){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(m==n-1){
        int p=100,q;
        for(int i=1;i<=n;i++){
            int v=g(a[i]);
            if(v<p){
                p=v;
                q=i;
            }
        }
        if(q!=1){
            sum=a[1];
        }
        else{
            sum=a[2];
        }
        for(int i=1;i<=n;i++){
            if(i!=q){
                sum&=a[i];
            }
        }
        cout<<sum;
        return 0;
    }
    for(int i=1023;i>=0;i--){
        int mp=0;
        for(int j=1;j<=n;j++){
            if((a[j]&i)==i){
                mp++;
            }
        }
        if(mp>=m){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
