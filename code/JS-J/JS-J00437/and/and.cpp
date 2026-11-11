#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int tand(int a,int b){
    int bits[32]={},ba[32]={},bb[32]={};
    int i=0;
    while(a>0){
        if(a%2!=0) ba[31-i]=1;
        else ba[31-i]=0;
        a=a>>1;
        i++;
    }
    i=0;
    while(b>0){
        if(b%2!=0) bb[31-i]=1;
        else bb[31-i]=0;
        b=b>>1;
        i++;
    }
    for(int i=0;i<=31;i++) bits[i]=ba[i]&&bb[i];
    for(int i=0;i<=31;i++) cout<<ba[i];
    int answ=0;
    for(int i=0;i<=31;i++){
        answ+=bits[i];
        if(i!=31) answ=answ<<1;
    }
    return answ;
}
int max_and(int m,int L){
    int maxn=-1;
    if(L==n-1 || m==0) return a[L];
    for(int i=L+1;i<n && m>=1;i++){
        maxn=max(maxn,max_and(m-1,i));
    }
    return tand(a[L],maxn);
    return maxn;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<max_and(m,0);
    return 0;
}
