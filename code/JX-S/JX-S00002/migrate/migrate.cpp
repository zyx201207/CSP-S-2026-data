#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,b;
int x[200005],num=0;
int main(){
    freopen ("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[i];
            b=0+x[i];
        }
        for(int j=1;j<=n;j++){
                do{
                    if(d>b){
                        num++;
                    }
                }while(b-=x[i]);
                do{
                    if(d>b){
                        num++;
                    }
                }while(b-=x[n-i]);

        }
        cout<<num/2;
    }
}
