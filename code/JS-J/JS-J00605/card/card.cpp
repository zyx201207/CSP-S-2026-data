#include<bits/stdc++.h>
using namespace std;
int m,n,k;
bool flag=1;
int a[300005],b[300005],t[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]<a[i-1])flag=0;}
    if(m==1){
        cout<<n;
        return 0;
    }
    if(flag){
        int nn=n;
    while(nn--){
        memset(b,0,sizeof(b));
        k=0;
        for(int i=n-nn;i<=n;i++){
            if(b[k]!=a[i])b[++k]=a[i];
        }
        for(int i=1;i<=k;i++){t[b[i]]++;}
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
    }
    int nn=n;
    while(nn--){
        memset(b,0,sizeof(b));
        k=0;
        for(int i=n-nn;i<=n;i++){
            int r=-1;
            for(int j=1;j<=k;j++){
                if(b[j]==a[i]){
                    r=j;
                    break;
                }
            }
            if(r==-1)b[++k]=a[i];
            else{
                while(k!=r){
                    b[k]=0;
                    k--;
                }
            }
        }
        for(int i=1;i<=k;i++){t[b[i]]++;}
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
return 0;
}
