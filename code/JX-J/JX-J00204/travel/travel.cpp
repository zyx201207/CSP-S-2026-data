#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    char x[10005],y[10005];
    int m,n,c,d;
    cin>>m>>a>>n>>b;
    for(int i=0,i<3;i++){
        x[i]=a[i];
        y[i]=b[i];
    }
    c=x[2]-0;
    d=y[2]-0;
    if(m==n){
        cout<<1;
        if(y[0]==x[0]&&x[1]==y[1]){
            cout<<1;
            if(c<=67&&d<=67||c>67&&d>67){
                cout<<1;
                if(abs(c-d)==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            cout<<0<<0;
        }
        else{
            cout<<0<<0<<0
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }

    return 0;
}


