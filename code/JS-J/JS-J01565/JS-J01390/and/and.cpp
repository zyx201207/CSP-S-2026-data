#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long d=0;
bool b[200005];
int n;
long long awy(long long a,long long b){
    long long l=2;
    long long k=0;
    for(int i=1;i<=32;i++){
        if((a%l==(l/2))&&(b%l==(l/2))){
            k+=(l/2);
        }
        if(a%l){
            a-=(l/2);
        }
        if(b%l){
            b-=(l/2);
        }
        l*=2;
    }
    return k;
}
void dfs(int f,long long e,int c){
    if(c==0){
        d=max(d,e);
        return ;
    }
    for(int i=f+1;i<=n-c;i++){
        if(!b[i]&&(awy(e,a[i])>d)){
            b[i]=1;
            dfs(i,awy(e,a[i]),c--);
            b[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long s=1;
    long long f=0;
    for(int i=1;i<=32;i++){
        f+=s;
        s*=2;
    }
    dfs(0,f,m);
    cout<<d;
    return 0;
}
