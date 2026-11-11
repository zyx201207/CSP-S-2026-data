#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int z=1;z<=n;z++){
        int l=0;
        for(int i=z;i<=n;i++){
            bool f=0;
            int x;
            for(int j=1;j<=l;j++){
                if(b[j]==a[i]){
                    f=1;
                    x=j;
                    break;
                }
            }
            if(f==0){
                l++;
                b[l]=a[i];
            }else{
                for(int j=x+1;j<=l;j++){
                    b[j]=0;
                }
                l=x;
            }
        }
        for(int k=1;k<=l;k++){
                c[b[k]]++;
            }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
