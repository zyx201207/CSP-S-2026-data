#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200001]={};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long re=-1;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                re=max(re,a[i]&a[j]);
            }
        }
    }if(m==3){
        for(int q=1;q<=n;q++){
            for(int i=q+1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    re=max(re,a[i]&a[j]&a[q]);
                }
            }
        }
    }if(m==4){
        for(int w=1;w<=n;w++){
            for(int q=w+1;q<=n;q++){
                for(int i=q+1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        re=max(re,a[i]&a[j]&a[q]);
                    }
                }
            }
        }
    }
    cout<<re;
}
