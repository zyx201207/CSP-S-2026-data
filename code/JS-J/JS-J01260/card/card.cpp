#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int d[300005];
int e[500005];
int f[300005];
int cnt=1;
int n,m;
void l(int x){
    for(int i=x;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[j]=0;
            b[j]=0;
        }
        if(c[a[i]]!=0){cnt=c[a[i]]+1;
            for(int j=c[a[i]]+1;j<i;j++){
                c[b[j]]=0;
                b[j]=0;
            }
        }else{
            b[cnt]=a[i];
            c[b[cnt]]=cnt;
            cnt++;
        }
    }
}
int main(){
    freopen("card1.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        l(i);

        }for(int j=1;j<=n;j++){
            d[b[j]]++;
        }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<' ';
    }
    return 0;
}
