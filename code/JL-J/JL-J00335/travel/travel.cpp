#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    string pai1,pai2,wei1,wei2;
    pai1=s1.substr(0,2);
    wei1=s1.substr(2,1);
    pai2=s2.substr(0,2);
    wei2=s2.substr(2,1);
    if(c1==c2)
    {
        cout<<1;
        if(pai1==pai2)
        {
            cout<<1;
            if((wei1=="A"&&wei2=="B")||(wei1=="B"&&wei2=="A")||(wei1=="A"&&wei2=="C")||
            (wei1=="C"&&wei2=="A")||(wei1=="B"&&wei2=="C")||(wei1=="C"&&wei2=="B")||(wei1=="D"&&wei2=="F")||(wei1=="F"&&wei2=="D"))
            {
                cout<<1;
                if((wei1=="A"&&wei2=="B")||(wei1=="B"&&wei2=="A")||(wei1=="B"&&wei2=="C")||(wei1=="C"&&wei2=="B")||(wei1=="D"&&wei2=="F")||(wei1=="F"&&wei2=="D"))
                {
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
        cout<<0;

}
