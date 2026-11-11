#include<bits/stdc++.h>
using namespace std;
int n[10000],a,b,t=0,u[1000],mj;
int f(int h ,int g){
    int d[1000],p[1000],r=0,k=0,l=0;
    while(h>0){
        d[r]=h%2;
        h=h/2;
        r+=1;
    }
    while(g>0){
        p[k]=g%2;
        g=g/2;
        k+=1;
    }
    if(k>r){
        r=k;
    }
    for(int i=0;i<r;i++){
        if(d[i]==1 and p[i]==1){
            u[i]=1;
        }
        else{
            u[i]=0;
        }
    }
    for(int i=r-1;i>=0;i++){
        l=l*2;
        l+=u[i];
    }
    return l;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            if(n[j]>n[i]){
                mj=n[j];
                n[j]=n[i];
                n[i]=mj;
            }
        }
    }
    mj=n[1];
    for(int i=1;i<b;i++){
        mj=f(mj,n[i]);
    }
    cout<<mj;
}
