#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c[n]={0};
    int b=0,d=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i]=a[i];
            c[i]+=1;
            d+=1;
            if(c[i]==c[i+1]){
                break;
            }

        }

        for(int k=1;k<=n;k++){
                if(c[i]==c[k+1]){
                    b+=1;
            }
            if(b==n){
                break;
            }
        }



    }
    cout<<b;




    return 0;
}
