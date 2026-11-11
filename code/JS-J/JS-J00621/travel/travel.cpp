#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;char st1,st2;bool f1,f2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>st1>>c2>>s2>>st2;
    f1=(st1=='D'||st1=='F');
    f2=(st2=='D'||st2=='F');
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"1";
            if(f1==f2){
                cout<<"1";
                if(abs(st1-st2)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
