#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,w=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int p=0;
        while(x!=0){
            p=p*10+x%2;
            x=x/2;
        }
        while(p>0){
            a[i]+=p%10;
            p=p/10;
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(i!=j&&(a[i]^a[j]>maxn)){
                    maxn=a[i]^a[j];
                }
            }
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>maxn) maxn=a[i];
        }
    }
    int f=0;
    if(m==n){
        for(int i=1;i<=n;i++){
            if(f==0){
                w+=a[i];
                f=1;
            }else{
                w=w+w^a[i];
            }
        }
    }
    if(m==n){
        cout<<w;
    }else{
        cout<<maxn;
    }
    return 0;
}


