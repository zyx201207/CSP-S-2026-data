#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,t=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int x=0;x<=n;x++){
        for(int i=x;i<=n;i++){
            for(int j=0;j<t;j++){
                if(b[j]==a[i]){
                    for(int k=j;k<t;k++){
                        b[k]=0;
                        t--;
                    }
                    t--;
                }
            }
            b[t]=a[i];


            t++;
        }

        for(int l=0;l<t;l++){
            c[b[l]]++;
            b[l]=0;
        }
        t=0;


    }
    for(int i=0;i<m;i++){
        cout<<c[i+1]<<" ";
    }
return 0;
}
