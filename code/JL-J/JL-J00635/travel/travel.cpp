#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xx,xh,rx,rh;
    cin>>xx>>xh>>rx>>rh;
    if(xx!=rx)
    {
        cout<<"0000";
        return 0;
    }else
    {
        cout<<1;
        if(xh[0]!=rh[0])
        {
            cout<<"000";
            return 0;
        }else
        {
            if(xh[1]!=rh[1])
            {
                cout<<"000";
            }else
            {
                cout<<'1';
                if(xh[2]<='C'&&rh[2]<='C')
                {
                    cout<<1;
                    if(xh[2]-1!=rh[2]&&xh[2]+1!=rh[2])
                    {
                        cout<<0;
                    }else{
                        cout<<1;
                    }
                }else if(xh[2]>='D'&&rh[2]>='D')
                {
                    cout<<1;
                    if(xh[2]-1!=rh[2]&&xh[2]+1!=rh[2])
                    {
                        cout<<0;
                    }else{
                        cout<<1;
                    }
                }else{
                    cout<<"00";
                }
            }
        }
    }

    return 0;
}
