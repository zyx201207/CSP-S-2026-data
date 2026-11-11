#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3) cout<<"0000";
    else {
        cout<<1;
        string p1,p2;
        p1=s2[0]+s2[1],p2=s4[0]+s4[1];
        if(p1!=p2) cout<<"000";
        else{
            cout<<1;
            if(!(s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s4[2]>'C')) cout<<"00";
            else{
                cout<<1;
                if(abs((int)s2[2]-(int)s4[2])==1) cout<<1;
                else cout<<0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
