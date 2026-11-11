#include <bits/stdc++.h>
using namespace std;

int n,m,a[100001],b[100001][100001];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=0;
    }
    for(int i=1;i<=n-1;i++);
        for(int j=i+1;j<=n;j++)
        if(a[i]<a[j]){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    if(m==1){
        printf("%d",a[1]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int x=1;
        for(int j=1;j<=n;j++){
            b[i][j]+=a[i]%2;
            a[i]/=2;
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n){
            if(b[i][j]==b[i-1][j]){
                b[i][j]=b[i][j];
            }
            else
                b[i][j]=0;
        }
    }
    int x=1;
    for(int i=1;i<=n;i++){
        sum+=x*b[m][i];
        x*=2
    }
    printf("%d",sum);
}

