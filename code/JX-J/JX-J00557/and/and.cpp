#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,f[200005],g,h,f2[40],fw=1,fvv=1,SB[5],gun[200005],GUN=1;
void dfs(long long x){
    if(x>n){
        g=0;
        for(int i=1;i<=n;i++){
            if(f[i]&&!g) h=a[i],g++;
            if(f[i]&&g) (h&=a[i]),g++;
        }
        if(g!=m) return;
        s=max(s,h);
        return;
    }
    f[x]=1;
    dfs(x+1);
    f[x]=0;
    dfs(x+1);
}
long long POW(long long x){
    int y=1;
    for(int i=0;i<x;i++) y*=2;
    return y;
}
bool p(long long x){
    for(int i=1;i<31;i++) if(x==f2[i]-1) return 1;
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=1;i<31;i++) f2[i]=POW(i);
    for(int i=1;i<200001;i++){
        if(i==f2[GUN]) GUN++;
        gun[i]=f2[GUN]-1;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!p(a[i])) fw=0;
        if(a[i]<5) SB[a[i]]++;
        if(a[i]!=i-1) fvv=0;
    }
    if(fw){
        sort(a+1,a+n+1);
        cout<<a[n+1-m];
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++) s=max(s,a[i]);
        cout<<s;
        return 0;
    }
    if(m==n){
        s=a[1];
        for(int i=2;i<=n;i++) (s&=a[i]);
        cout<<s;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) s=max(s,(a[i]&a[j]));
        cout<<s;
        return 0;
    }
    if(SB[0]+SB[1]+SB[2]+SB[3]+SB[4]==n){
        if(SB[4]>=m){
            cout<<4;
            return 0;
        }
        if(SB[3]>=m){
            cout<<3;
            return 0;
        }
        if(SB[3]+SB[2]>=m){
            cout<<2;
            return 0;
        }
        if(SB[1]>=m){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(n<21){
        dfs(0);
        cout<<s;
        return 0;
    }
    if(fvv){
        cout<<n-1-gun[m-1];
        return 0;
    }
    return 0;
}
