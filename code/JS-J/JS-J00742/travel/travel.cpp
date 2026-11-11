#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,cx;
    string setr,setx;
    cin>>cr>>setr>>cx>>setx;
    if(cr==cx)
        if(setr[0]==setx[0] && setr[1]==setx[1])
            if((setr[2]<=67 && setx[2]<=67) || (setr[2]>67 && setx[2]>67))
                if(abs(setr[2]-setx[2])==1)
                    cout<<"1111"<<endl;
                else
                    cout<<"1110"<<endl;
            else
                cout<<"1100"<<endl;
        else
            cout<<"1000"<<endl;
    else
        cout<<"0000"<<endl;
    return 0;
}
