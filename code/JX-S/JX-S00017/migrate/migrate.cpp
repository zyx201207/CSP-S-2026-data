include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int h=0;h<t;h++){
        int n,d,suma=0;
        cin>>n>>d;
        int a[n],b[n-1],c[n-2],e[n-3];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            b[i]=a[i+1]-a[i];
        }
        for(int i=0;i<n-2;i++){
            c[i]=b[i+1]+b[i];
        }
        for(int i=0;i<n-3;i++){
            e[i]=b[i+2]+b[i+1]+b[i];
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int s=0;
                for(int k=i;k<j-2;k++){
                    if(c[k]<=d && c[k+1]<=d && e[k]>d){
                        s++;
                    }
                }
                if(s==1){
                    suma++;
                }
            }
        }
        cout<<suma;
    }
    return 0;
}
