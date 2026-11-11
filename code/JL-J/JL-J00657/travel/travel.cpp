#include<bits/stdc++.h>
using namespace std;
string r,x,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>r;
    cin>>c2>>x;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        if(r[1]==x[1]&&r[0]==x[0]){
            cout<<1;
            if(r[2]<='C'&&r[2]>='A'&&x[2]<='C'&&x[2]>='A'||r[2]<='F'&&r[2]>='D'&&x[2]<='F'&&x[2]>='D'){
                cout<<1;
                if(abs((int)(r[2]-x[2]))==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }

        }
        else{
            cout<<"000";
            return 0;
        }
    }
    return 0;
}

