#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[1000];
    int b[1000];
    int c[1000];
    int d[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=i;j++){
            if(b[j-1]!=a[i]){
                b[j]=a[i];
            }
            else{
                b[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i+1]!=0&&a[i]>a[i+1]){
            int e=a[i];
            a[i]=a[i+1];
            a[i+1]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i-1]==a[i]){
            for(int j=1;j<=n;j++){
                c[i]=0;
            }
        }
        else{
            c[i]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a[j]==c[k]){
                    d[i]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
