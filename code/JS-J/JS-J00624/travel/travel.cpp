#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool x=0,y=0,z=0,k=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]){
        x=1;
        cout<<x;
            if(b[1]==d[1]){
                y=1;
                cout<<y;
                if((d[2]=='C'&&b[2]=='D')||(b[2]=='C'&&d[2]=='D')){
                        cout<<z<<k;
                }
                else{
                    z=1;
                    cout<<z;
                    if((d[2]-b[2]==1)||(d[2]-b[2]==-1)){
                        k=1;
                        cout<<k;
                    }
                    else{
                        cout<<k;
                    }
                }
            }
            else{
                cout<<y<<z<<k;
            }
        }
    else{
        cout<<x<<y<<z<<k;
    }
    return 0;
}
