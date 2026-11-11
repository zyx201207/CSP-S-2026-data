#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=0,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>maxn){
                    maxn=a[i]&a[j];
                }
            }
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>maxn){
                maxn=a[i];
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        if((a[i]&a[j]&a[k])>maxn){
                            maxn=a[i]&a[j]&a[k];
                        }
                    }
            }
        }
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int p=k+1;p<=n;p++){
                            if((a[i]&a[j]&a[k]&a[p])>maxn){
                                maxn=a[i]&a[j]&a[k]&a[p];
                            }
                        }
                    }

                    }
            }
    }
    if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int p=k+1;p<=n;p++){
                                for(int q=p+1;q<=n;q++){
                                    if((a[i]&a[j]&a[k]&a[p]&a[q])>maxn){
                                        maxn=a[i]&a[j]&a[k]&a[p]&a[q];
                            }
                                }

                        }
                    }

                    }
            }
    }
    cout<<maxn;
    return 0;
}
