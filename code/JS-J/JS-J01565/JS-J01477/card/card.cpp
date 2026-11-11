#include <bits/stdc++.h>
using namespace std;
const int Maxn=500005;
long long a[Maxn],b[Maxn][Maxn],c[Maxn],d[Maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k;
    bool z=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=m;j++){
            if(c[j]==a[i]){
                z=false;
            }else if(c[j]!=a[i]){
                z=true;
            }
        }
        if(z==true){
            int x=1;
            c[x]=a[i];
            x++;
        }
    }
    sort(c+1,c+m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            k=a[j];
            for(int x=j+1;x<=n;x++){
                if(a[x]==k){
                    for(int y=j;y<=x;y++){
                        a[y]=0;
                    }
                }
            }
            b[i][j]=a[j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                if(b[x][y]==c[i]){
                    d[i]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
