#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[200005],maxn=0;
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
if(m==2){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]&&a[i]>maxn){
                maxn=a[i];

            }
            else if(a[j]<a[i]&&a[j]>maxn){
                maxn=a[j];
            }

        }
    }
}
if(m==3){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+2;k<=n;k++){
                if(a[i]<a[j]&&a[i]<a[k]&& a[i]>maxn){
                    maxn=a[i];

                }
                else if(a[j]<a[i]&&a[j]<a[k] &&a[j]>maxn){
                    maxn=a[j];
                }
                else if(a[k]<a[i]&&a[k]<a[j] &&a[k]>maxn){
                    maxn=a[k];
                }
            }

        }
    }
}
if(m==4){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+2;k<=n;k++){
                for(int m=i+3;m<=n;m++){
                    if(a[i]<a[j]&&a[i]<a[k]&& a[i]<a[m]&&a[i]>maxn){
                        maxn=a[i];

                    }
                    else if(a[j]<a[i]&&a[j]<a[k] &&a[j]<a[m]&&a[j]>maxn){
                        maxn=a[j];
                    }
                    else if(a[k]<a[i]&&a[k]<a[j] &&a[k]<a[m]&&a[k]>maxn){
                        maxn=a[k];
                    }
                    else if(a[m]<a[i]&&a[m]<a[j] &&a[m]<a[k]&&a[m]>maxn){
                        maxn=a[m];
                    }
            }

        }
    }
}
if(m==5){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+2;k<=n;k++){
                for(int m=i+3;m<=n;m++){
                    for(int p=i+4;p<=n;p++){
                        if(a[i]<a[j]&&a[i]<a[k]&& a[i]<a[m]&&a[i]<a[p]&&a[i]>maxn){
                            maxn=a[i];

                        }
                        else if(a[j]<a[i]&&a[j]<a[k] &&a[j]<a[m]&&a[j]<a[p]&&a[j]>maxn){
                            maxn=a[j];
                        }
                        else if(a[k]<a[i]&&a[k]<a[j] &&a[k]<a[m]&&a[k]<a[p]&&a[k]>maxn){
                            maxn=a[k];
                        }
                        else if(a[m]<a[i]&&a[m]<a[j] &&a[m]<a[k]&&a[m]<a[p]&&a[m]>maxn){
                            maxn=a[m];
                        }
                        else if(a[p]<a[i]&&a[p]<a[j] &&a[p]<a[k]&&a[p]<a[m]&&a[p]>maxn){
                            maxn=a[p];
                        }
                    }
            }

        }
    }
}
if(m==6){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+2;k<=n;k++){
                for(int m=i+3;m<=n;m++){
                    for(int p=i+4;p<=n;p++){
                        for(int q=i+5;q<=n;q++){
                        if(a[i]<a[j]&&a[i]<a[k]&& a[i]<a[m]&&a[i]<a[p]&&a[i]<a[q]&&a[i]>maxn){
                            maxn=a[i];

                        }
                        else if(a[j]<a[i]&&a[j]<a[k] &&a[j]<a[m]&&a[j]<a[p]&&a[j]<a[q]&&a[j]>maxn){
                            maxn=a[j];
                        }
                        else if(a[k]<a[i]&&a[k]<a[j] &&a[k]<a[m]&&a[k]<a[p]&&a[k]<a[q]&&a[k]>maxn){
                            maxn=a[k];
                        }
                        else if(a[m]<a[i]&&a[m]<a[j] &&a[m]<a[k]&&a[m]<a[p]&&a[m]<a[q]&&a[m]>maxn){
                            maxn=a[m];
                        }
                        else if(a[p]<a[i]&&a[p]<a[j] &&a[p]<a[k]&&a[p]<a[m]&&a[p]<a[q]&&a[p]>maxn){
                            maxn=a[p];
                        }
                        else if(a[q]<a[i]&&a[q]<a[j] &&a[q]<a[k]&&a[q]<a[m]&&a[q]<a[p]&&a[q]>maxn){
                            maxn=a[q];
                        }
                    }
            }

        }
    }
}
if(m==7){
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+2;k<=n;k++){
                for(int m=i+3;m<=n;m++){
                    for(int p=i+4;p<=n;p++){
                        for(int q=i+5;q<=n;q++){
                            for(int t=i+6;t<=n;t++){
                        if(a[i]<a[j]&&a[i]<a[k]&& a[i]<a[m]&&a[i]<a[p]&&a[i]<a[q]&&a[i]<a[t]&&a[i]>maxn){
                            maxn=a[i];

                        }
                        else if(a[j]<a[i]&&a[j]<a[k] &&a[j]<a[m]&&a[j]<a[p]&&a[j]<a[q]&&a[j]<a[t]&&a[j]>maxn){
                            maxn=a[j];
                        }
                        else if(a[k]<a[i]&&a[k]<a[j] &&a[k]<a[m]&&a[k]<a[p]&&a[k]<a[q]&&a[k]<a[t]&&a[k]>maxn){
                            maxn=a[k];
                        }
                        else if(a[m]<a[i]&&a[m]<a[j] &&a[m]<a[k]&&a[m]<a[p]&&a[m]<a[q]&&a[m]<a[t]&&a[m]>maxn){
                            maxn=a[m];
                        }
                        else if(a[p]<a[i]&&a[p]<a[j] &&a[p]<a[k]&&a[p]<a[m]&&a[p]<a[q]&&a[p]<a[t]&&a[p]>maxn){
                            maxn=a[p];
                        }
                        else if(a[q]<a[i]&&a[q]<a[j] &&a[q]<a[k]&&a[q]<a[m]&&a[q]<a[p]&&a[q]<a[t]&&a[q]>maxn){
                            maxn=a[q];
                        }
                        else if(a[t]<a[i]&&a[t]<a[j] &&a[t]<a[k]&&a[t]<a[m]&&a[t]<a[p]&&a[t]<a[q]&&a[t]>maxn){
                            maxn=a[t];
                        }
                    }
            }

        }
    }
}
cout<<maxn;
return 0;
}

