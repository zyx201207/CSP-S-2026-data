#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
long long maxn,andn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(i==1) andn=a[i];
        else andn&=a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        cout<<andn;
        return 0;
    }
    if(m==n-1){
        long long pron=a[2];
        maxn=-1;
        for(int i=3;i<=n;i++){
            pron&=a[i];
        }
        maxn=max(maxn,pron);
        for(int i=2;i<=n;i++){
            pron=a[1];
            for(int j=2;j<=n;j++){
                if(j==i) continue;
                pron&=a[j];
            }
            maxn=max(maxn,pron);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long pron=a[i] & a[j];
                maxn=max(maxn,pron);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==3){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    long long pron=a[i] & a[j] & a[k];
                    maxn=max(maxn,pron);
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==4){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        long long pron=a[i] & a[j] & a[k] & a[q];
                        maxn=max(maxn,pron);
                    }
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==5){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            long long pron=a[i] & a[j] & a[k] & a[q] & a[w];
                            maxn=max(maxn,pron);
                        }
                    }
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==6){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            for(int e=w+1;e<=n;e++){
                                long long pron=a[i] & a[j] & a[k] & a[q] & a[w] & a[e];
                                maxn=max(maxn,pron);
                            }
                        }
                    }
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==7){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            for(int e=w+1;e<=n;e++){
                                for(int r=e+1;r<=n;r++){
                                    long long pron=a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r];
                                    maxn=max(maxn,pron);
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
    if(m==8){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            for(int e=w+1;e<=n;e++){
                                for(int r=e+1;r<=n;r++){
                                    for(int t=r+1;t<=n;t++){
                                        long long pron=a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t];
                                        maxn=max(maxn,pron);
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
    if(m==9){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            for(int e=w+1;e<=n;e++){
                                for(int r=e+1;r<=n;r++){
                                    for(int t=r+1;t<=n;t++){
                                    for(int y=t+1;y<=n;y++){
                                            long long pron=a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t] & a[y];
                                            maxn=max(maxn,pron);
                                        }
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
    if(m==10){
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int q=k+1;q<=n;q++){
                        for(int w=q+1;w<=n;w++){
                            for(int e=w+1;e<=n;e++){
                                for(int r=e+1;r<=n;r++){
                                    for(int t=r+1;t<=n;t++){
                                        for(int y=t+1;y<=n;y++){
                                            for(int u=y+1;u<=n;u++){
                                                long long pron=a[i] & a[j] & a[k] & a[q] & a[w] & a[e] & a[r] & a[t] & a[y] & a[u];
                                                maxn=max(maxn,pron);
                                            }
                                        }
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
    return 0;
}
