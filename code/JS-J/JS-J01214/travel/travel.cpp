#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    a[0]*=10;
    a[5]*=10;
    a[2]*=10;
    a[7]*=10;
    int x=a[1]+a[0],y=a[6]+a[5];
    int p1=a[3]+a[2],p2=a[8]+a[7];
    if(x==y){
        cout<<1;
        if(p1==p2){
            cout<<1;
            if(a[4]<='C'&&a[9]>='D'){
                cout<<0;
                cout<<0;
            }
            else if(a[9]<='C'&&a[4]>='D'){
                cout<<0;
                cout<<0;
            }
            else{
                cout<<1;
                if(a[9]+1==a[4]||a[9]-1==a[4]){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
        }
        else{
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
