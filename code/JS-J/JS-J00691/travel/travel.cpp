#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1!=t1){
        cout<<"0000\n";
        return 0;
    }
    else{
        cout<<"1";
        string car1=s2.substr(0,2),car2=t2.substr(0,2);
        if(car1!=car2){
            cout<<"000\n";
            return 0;
        }
        else{
            cout<<"1";
            char st1=s2[2],st2=t2[2];
            bool f=(st1<='C' and st2<='C' or st1>='D' and st2>='D');
            if(!f){
                cout<<"00\n";
                return 0;
            }
            else{
                cout<<"1";
                if(st1=='A' and st2=='C' or st1=='C' and st2=='A'){
                    cout<<"0\n";
                    return 0;
                }
                else cout<<"1\n";
                return 0;
            }
        }
    }
    return 0;
}
