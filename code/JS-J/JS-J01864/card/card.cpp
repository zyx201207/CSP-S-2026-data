#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[300005];
bool f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(!f[a[j]) f[a[j]=1;
            else{
                int st=a[j],sk=j-1;
                while(st!=a[sk]){
                    f[sk]=0;
                    sk--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            b[i]+=j[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
