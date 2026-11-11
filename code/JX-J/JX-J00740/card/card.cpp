#include<bits/stdc++.h>
using namespace std;
int n,m,l[500010],r[500010],a[500010],b[300010],w[500010],cnt,c[300010];
void qwe(int x,int y){
    cnt=0;
    for(int i=x;i<=y;i++){
        cnt++;
        w[cnt]=a[i];
        for(int j=1;j<=cnt;j++){
            if(w[j]==a[i]){
                for(int k=j;k<cnt;k++){
                    w[k]=0;
                }
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(w[i]!=0) b[w[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=5000){
        for(int i=1;i<=n;i++){
            c[a[i]]++;
        }
        int sum=0;
        for(int i=1;i<=m;i++){
            sum+=c[i];
            cout<<sum<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        qwe(i,n);
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
