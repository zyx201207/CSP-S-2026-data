#include<bits/stdc++.h>
using namespace std;
long long n,m,t=0;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==2){
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]!=a[j]){
                if(a[i]&a[j]>t)t=a[i]&a[j];
            }
        }
    }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(a[i]!=a[j]&&a[i]!=a[k]){
                        if(a[i]&a[j]&a[k]>t)t=a[i]&a[j]&a[k];
                    }
                }
            }
         }
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    for(int h=1;h<=n;h++){
                        if(a[i]!=a[j]&&a[i]!=a[k]&&a[i]!=a[h]){
                           if(a[i]&a[j]&a[k]&a[h]>t)t=a[i]&a[j]&a[k]&a[h];
                        }
                    }
                }
            }
         }
       }
       if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    for(int h=1;h<=n;h++){
                        for(int g=1;g<=n;g++){
                            if(a[i]!=a[j]&&a[i]!=a[k]&&a[i]!=a[h]&&a[i]!=a[g]){
                                if(a[i]&a[j]&a[k]&a[h]&a[g]>t)t=a[i]&a[j]&a[k]&a[h]&a[g];
                            }
                        }
                    }
                }
            }
         }
       }
    cout<<t;
    return 0;
}
