#include<bits/stdc++.h>
using namespace std;
struct v{
    long long f;
    long long g;
};
long long n,m,k=1;
v a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].f;
    }
    for(int i=1;i<=n;i++){
        k=0;
        long long l[m+5]={0};
        for(int j=i;j<=n;j++){
            int u=0;
            for(int o=1;o<=k;o++){
                if(l[o]==a[j].f){
                    u=o;
                }
            }
            if(u==0){
                ++k;
                l[k]=a[j].f;
            }
            else{
                k=u;
            }
        }
        for(int i=1;i<=k;i++){
            a[l[i]].g++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i].g<<" ";
    }
    return 0;
}
