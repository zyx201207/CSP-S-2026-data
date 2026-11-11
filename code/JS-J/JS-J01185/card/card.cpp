#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[300005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i]=0;
        }
        bool aaa=false;
        for(int j=i;j<=n;j++){
            for(int c=i;c<j;c++){
                if(a[c]==a[j]&&b[c]!=-1&&!aaa){
                    aaa=true;
                }
                if(aaa){
                    b[c]=-1;
                }
            }
            aaa=false;
        }
        for(int j=1;j<=n;j++){
            if(b[j]!=-1){
                d[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
