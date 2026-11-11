#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1;
    string c2;
    string c3;
    string c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3)
    {
        cout<<1;
        if(c2==c4)
        {
            cout<<1;
            if(c2[3]=='A'||c2[3]=='B'||c2[3]=='C')
            {
                if(c4[3]=='A'||c4[3]=='B'||c4[3]=='C')
                {
                    cout<<1;
                    if(int(c4[3])+1==int(c2[3])||int(c4[3])-1==int(c2[3]))
                        cout<<1;
                    else
                        cout<<0;
                }
                else
                    cout<<00;
            }
           else{
                if(c2[3]=='F'||c2[3]=='D')
                {
                    if(c4[3]=='F'||c4[3]=='D')
                    {
                        cout<<1;
                        if(int(c4[3])+1==int(c2[3])||int(c4[3])-1==int(c2[3]))
                            cout<<1;
                        else
                             cout<<0;
                    }
                }
                else
                    cout<<00;
           }
        }
        else
            cout<<000;
    }
    else
    {
        cout<<0000;
    }
    return 0;
}
