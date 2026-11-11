#include <bits/stdc++.h>
using namespace std;

string r1,x1,r2,x2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    char rc=r2[2],xc=x2[2];
    if(r1==x1){
        cout<<1;
        if(r2[0]==x2[0]&&r2[1]==x2[1]){
            cout<<1;
            if(rc=='A'||rc=='B'||rc=='C'){
                if(xc=='A'||xc=='B'||xc=='C'){
                    cout<<1;
                    if(rc-xc==1||xc-rc==1){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
                }
                else{
                    cout<<0<<0;
                }
            }
            else if(xc=='D'||xc=='F'){
                cout<<1;
                if(rc-xc==1||xc-rc==1){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }

    return 0;
}
