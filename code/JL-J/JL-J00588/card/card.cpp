#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500005],b[500005]={0},t=0,w=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int z=w;z<=n;z++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]==b[j]){
                    for(int k=j;k<=n;k++){
                        b[k]=0;
                    }
                    b[j]=a[i];
                    t=j+1;
                }else{
                    b[t]=a[i];
                    t++;
                }
            }
        }
        for(int i=-1;i<=t-1;i++){
            b[a[i]]++;
        }
        w++;
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}

