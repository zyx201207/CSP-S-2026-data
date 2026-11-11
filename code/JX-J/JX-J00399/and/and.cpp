#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cnt[200005],maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    if(n==m){
        maxn=a[1];
        for(int i=2;i<=n;i++)maxn&=a[i];
    }
    else if(m==1){
        maxn=-1;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
    }
    else if(m==2){
        maxn=a[1]&a[2];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);

            }
        }
    }
    else if(m==3){
        maxn=a[1]&a[2]&a[3];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 for(int k=j+1;k<=n;k++){
                    maxn=max(maxn,a[i]&a[j]&a[k]);
                 }
            }
        }
    }
    else if(m==4){
        maxn=a[1]&a[2]&a[3]&a[4];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 for(int k=j+1;k<=n;k++){
                    for(int z=k+1;z<=n;z++){
                        maxn=max(maxn,a[i]&a[j]&a[k]&a[z]);
                    }
                 }
            }
        }
    }
    else if(m==5){
        maxn=a[1]&a[2]&a[3]&a[4]&a[5];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 for(int k=j+1;k<=n;k++){
                    for(int z=k+1;z<=n;z++){
                        for(int y=z+1;y<=n;y++){
                          maxn=max(maxn,a[i]&a[j]&a[k]&a[z]&a[y]);
                        }
                    }
                 }
            }
        }
    }
    else if(m==6){
        maxn=a[1]&a[2]&a[3]&a[4]&a[5]&a[6];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 for(int k=j+1;k<=n;k++){
                    for(int z=k+1;z<=n;z++){
                        for(int y=z+1;y<=n;y++){
                            for(int x=y+1;x<=n;x++){
                                maxn=max(maxn,a[i]&a[j]&a[k]&a[z]&a[y]&a[x]);
                            }
                        }
                    }
                 }
            }
        }
    }
    else if(m==7){
        maxn=a[1]&a[2]&a[3]&a[4]&a[5]&a[6]&a[7];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                 for(int k=j+1;k<=n;k++){
                    for(int z=k+1;z<=n;z++){
                        for(int y=z+1;y<=n;y++){
                            for(int x=y+1;x<=n;x++){
                                for(int w=x+1;w<=n;w++){
                                    maxn=max(maxn,a[i]&a[j]&a[k]&a[z]&a[y]&a[x]&a[w]);
                                }
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
