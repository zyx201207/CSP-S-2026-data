#include<bits/stdc++.h>
using namespace std;
long long x[200005];
char c[200005],a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long k=0;
    long long n;
    scanf("%lld",&n);
    long long l=0,r=0;
    for(long long i=1;i<=n;i+=1){
        scanf("%lld %c",&x[i],&c[i]);
        r+=x[i];
    }
    r-=1;
    long long l1=1,r1=n;
    while(l<r){
        if(x[r1]==0){
            r1-=1;
        }
        if(x[l1]==0){
            l1+=1;
        }
        if(c[r1]==c[l1]){
            if(x[r1]==x[l1]){
                r-=x[r1];
                l+=x[r1];
                r1-=1;
                l1+=1;
            }
            if(x[r1]<x[l1]){
                r-=x[r1];
                l+=x[r1];
                r1-=1;
                x[l1]-=x[r1];
            }
            if(x[r1]>x[l1]){
                r-=x[l1];
                l+=x[l1];
                l1+=1;
                x[r1]-=x[l1];
            }
        }
        else{
            if(x[r1]==x[l1]){
//                cout<<r<<' '<<l<<"   ";
                r-=x[r1];
                l+=x[r1];
                k+=x[r1];
                r1-=1;
                l1+=1;
//                cout<<r<<' '<<l<<"\n";
            }
            else if(x[r1]<x[l1]){
                r-=x[r1];
                l+=x[r1];
                k+=x[r1];
                x[l1]-=x[r1];
                r1-=1;
//                cout<<'a';
                
            }
            else if(x[r1]>x[l1]){
                r-=x[l1];
                l+=x[l1];
                k+=x[l1];
                x[r1]-=x[l1];
                l1+=1;
                
//                cout<<'c';
            }
        }
    }
    printf("%lld",k);
    return 0;
}