#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long p[32],q[32];
long long a[N],b[N];
long long m,n,Max=-1,tp=pow(2,31)-1,tq=pow(2,31)-1,Maxx=-1;
long long andde(long long a,long long b){
    int i=1,j=1;
    while(a!=0&&a!=1){
        p[i++]=a%2;
        a/=2;
    }
    p[i]=a;
    while(b!=0&&b!=1){
        q[j++]=b%2;
        b/=2;
    }
    q[i]=b;
    long long ct=0;
    for(int pt=1;pt<=min(i,j);pt++){
        if(p[pt]==1&&q[pt]==1){
            ct+=pow(2,pt-1);
        }
    }
    return ct;
}
void ppp(){
    tq=pow(2,31)-1;
    for(int i=1;i<=m;i++){
        tq=andde(tq,b[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        Max=max(a[i],Max);
        tp=andde(tp,a[i]);
    }
    if(m==1)cout<<Max;
    else if(m==n)cout<<tp;
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                Maxx=max(andde(a[i],a[j]),Maxx);
            }
        }
        cout<<Maxx;
    }
    else if(m==n-1){
        long long ctt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                else{
                    ctt+=andde(ctt,a[j]);
                }
            }
            Maxx=max(Maxx,ctt);
        }
        cout<<Maxx;
    }
    else{
        for(int i=1;i<=m;i++){
            b[i]=a[i];
            tq=andde(tq,b[i]);
        }
        for(int i=m+1;i<=n;i++){

            int maxxx=tq;
            int floo=0;
            for(int j=1;j<=m;j++){
                int tn=pow(2,31)-1;
                for(int k=1;k<=m;k++){
                    if(k==j)tn=andde(tn,a[i]);
                    else tn=andde(tn,b[k]);
                }
                if(tn>maxxx){
                    maxxx=tn;
                    floo=j;
                }
            }
            if(floo!=0)b[floo]=a[i];
            ppp;

        }
        cout<<tq;
    }
    return 0;
}
