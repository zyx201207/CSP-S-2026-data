#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e8;
long long a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int o=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int b[MAXN],c[MAXN],g[MAXN]; int y=a[i],x=a[j];int d=0,m=0;
            while(y){


                b[++d]=y%2;
                y/=2;
            }
            while(x){

            int y=a[i];
                c[++m]=x%2;
                x/=2;
            }
         int flag=0;
         for(int p=max(d,m);p>=1;p--){
            if(d>m){

                if(c[p]!=0){
                    flag++;}

                if(flag!=0){
                    if((b[p]==1)&&(c[p]==1)){
                        g[p]=1;
                    }
                    else{
                        g[p]=0;
                    }
                }
                else{
                    g[p]=b[p];
                }
            }
            if(d<m){

                if(b[p]!=0){
                    flag++;}

                if(flag!=0){
                    if((b[p]==1)&&(c[p]==1)){
                        g[p]=1;
                    }
                    else{
                        g[p]=0;
                    }
                }
                else{
                    g[p]=c[p];
                }

         }
         long long f,s;
         for(int w=max(d,m);w>=1;w--){
            int q=1;
            for(int i=1;i<=n;i++){
                q*=2;
            }
            f+=q*g[p];
         }
         if(f>o){
            o=f;
         }
         }
        }}
        cout<<o;
 return 0;
    }



