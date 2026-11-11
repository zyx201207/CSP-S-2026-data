#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    if(c==0){
        cin>>t;
        int n,d;
        for(int i=1;i<=t;i++){
            int a[3000000],b[3000000];
            cin>>n>>d;
            int flag=0;
            for(int j=1;j<=n;j++){
                cin>>a[j];
            }
            b[2]=a[2]-a[1];
            for(int j=3;j<=n;j++){
                b[j]=a[j]-a[j-1];
                if(b[j]!=b[j-1]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(n>=2*d){
                    cout<<2+n-2*d;
                    continue;
                }
            }
            for(int j=1;j<=n;j++){
                if(a[j+1]-a[j]>d){
                    continue;
                }
                if(a[j]-a[1]<d&&a[n]-a[j]<d){
                    cout<<0;
                    break;
                }
            }
            cout<<0;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
