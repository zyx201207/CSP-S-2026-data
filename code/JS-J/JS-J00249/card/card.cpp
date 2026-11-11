#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],cnt[N],n,m;
int OUT(int x,int y){
    int num=y;
    if(x==0){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(b[j]==i) cnt[i]++;
            }
        }
        return 0;
    }
    for(int i=n+1;i>y;i--){
        if(b[i]==x){
            num=i;
            for(int j=y+1;j<=i;j++){
                b[j]=0;
            }
        }
    }
    OUT(a[num+1],num+1);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        OUT(a[i],i);
        a[i]=0;
        for(int j=1;j<=n;j++) b[j]=a[j];
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
