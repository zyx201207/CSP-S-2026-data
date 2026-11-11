#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    int f[t];
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        int a[n],b[n],min0=d;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            b[j]=a[j+1]-a[j];
        }
        for(int j=0;j<n;j++){
            if(min0>b[j]){
                min0=b[j];
            }
        }
        if(min0=d){
            f[i]=0;
        }
        else{
            d=d/min0+1;
            f[i]=n/d;
        }
    }
    for(int i=0;i<t;i++){
        cout<<f[i]<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
