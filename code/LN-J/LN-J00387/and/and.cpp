#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool pan(long long n){
    int ans=n+1;
    while(ans>0){
        if(ans%2==1){
            return 0;
        }
        ans/=2;
        if(ans==1){
            return 1;
        }
    }
    return 0;
}
bool cmp(int a,int b){
    return a>b;
}
int ayub(int a,int b){
    if(pan(a)==1&&pan(b)==1){
        return min(a,b);
    }
    char a1[10000],b1[10000],c1[10000];
    int k1=0,k2=0;
    while(a>0){
        a1[++k1]=a%2;
        a/=2;
    }
    while(b>0){
        b1[++k2]=b%2;
        b/=2;
    }
    int wei=min(k1,k2);
    for(int i=1;i<=wei;i++){
        if(a1[i]==1&&b1[i]==1){
            c1[i]=1;
        }else{
            c1[i]=0;
        }
    }
    int sum=0,zhi=1;
    for(int i=1;i<=n;i++){
        sum+=c1[i]*zhi;
        zhi*=2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=-1,ans=-1,x=0,y=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ayub(a[i],a[j])>maxn){
                x=i,y=j;maxn=ayub(a[i],a[j]);
            }
        }
    }
    a[x]=0,a[y]=0;
    ans=maxn;
    m-=2;
    int z=0;
    maxn=-1;
    while(m--){
        for(int i=1;i<=n;i++){
            if(ayub(ans,a[i])>maxn){
                maxn=ayub(ans,a[i]);
                z=i;
            }
        }
        a[z]=0;
        ans=maxn;
    }
    cout<<ans;
    return 0;
}
