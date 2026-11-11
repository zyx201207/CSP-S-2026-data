#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],z[500010],y[500010],b,sz[300010],j=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        z[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        b=0;
        j=1;
        z[a[i-1]]--;
        memset(sz,0,sizeof(sz));
        for(int l=1;l<=m;l++){
            sz[l]=z[l];
        }
        for(int l=i;l<=n;l++){

            if(j==0){
                sz[a[l]]--;
                if(a[l]==b&&j==0){
                    j=1;
                    if(sz[a[l]]>1){
                        b=a[l];
                        j=0;
                    }
                }
                continue;
            }
            if(sz[a[l]]>1){
                j=0;
                b=a[l];
            }
        }
        for(int l=1;l<=m;l++){
            y[l]+=sz[l];
        }
    }
    for(int l=1;l<=m;l++){
        cout<<y[l]<<" ";
    }
    return 0;
}
