#include<bits/stdc++.h>
#define long long int
using namespace std;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string ch1,ch2,seat1,seat2;
    cin>>ch1>>seat1>>ch2>>seat2;
    if(ch1[0]==ch2[0]&&ch1[1]==ch2[1]) {
        cout<<1;
        if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]) {
            cout<<1;
            if((seat1[2]<='C'&&seat1[2]>='A'&&seat2[2]<='C'&&seat2[2]>='A')||(seat1[2]<='F'&&seat1[2]>='E'&&seat2[2]<='F'&&seat2[2]>='E')) {
                cout<<1;
                if(abs(seat1[2]-seat2[2])==1) cout<<1;
                else {
                    //cout<<endl;
                    cout<<0;
                }
            } else {
                //cout<<endl;
                cout<<"00";
            }
        } else {
            //cout<<endl;
            cout<<"000";
        }
    } else {
        cout<<"0000";
    }
    return 0;
}
//password:Trick||Treat!
