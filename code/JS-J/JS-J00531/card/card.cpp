#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],c[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            for(int k=j-1;k>i;k--){
                if(b[j]==b[k]){
                    for(int l=k;l<k;l++){
                        b[l]=0;
                    }
                }
            }
        }
        for(int p=i;p<=n;p++){
            if(a[p]!=0){
                c[a[p]]++;
            }
        }
        for(int i=1;i<=n;i++){

            b[i]=a[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }



    return 0;
}
