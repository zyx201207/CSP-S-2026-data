#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],c[100005],d[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>c[i];
        a[i]=c[i];
    }
    for(int i=1;i<=m;++i){
        for(int j=i;j<=n;++j){
            for(int z=1;z<j;++z){
                if(a[z]==a[j]){
                    for(int d=z;d<j;++d)a[d]=0;
                    break;
                }
            }
        }
        for(int j=1;j<=n;++j){
            if(a[j]!=0){
                b[a[j]]++;
            }
            a[j]=c[j];
        }
    }
    sort(c+1,c+n+1);
    for(int i=n;i>=1;--i){
        if(d[c[i]]==0){
            cout<<b[c[i]]<<" ";
            d[c[i]]=1;
        }

    }
    return 0;
}
