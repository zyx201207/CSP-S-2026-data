#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1,s1,c2,s2;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<"1";
            if(s1[2]>='A'&&s1[2]<='C'){
                if(s2[2]>='A'&&s2[2]<='C'){
                    cout<<"1";
                    if((min(s1[2],s2[2])+1)==max(s1[2],s2[2])){
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
                else{
                    cout<<"00";
                }
            }
            else{
                if(s2[2]>='D'&&s2[2]<='F'){
                    cout<<"1";
                    if((min(s1[2],s2[2])+1)==max(s1[2],s2[2])){
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
                else{
                    cout<<"00";
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    cout<<"\n";
    return 0;
}
