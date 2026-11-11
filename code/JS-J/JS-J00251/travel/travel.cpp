#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2){
        cout << "0000";
        return 0;
    }
    cout << "1";
    for(int i=0;i<s1.length()-1;i++){
        a=a*10+(s1[i]-'0');
    }
    for(int i=0;i<s2.length()-1;i++){
        c=c*10+(s2[i]-'0');
    }
    if(a==c){
        cout << "1";
        b=s1[s1.length()-1]-'A'+1;
        d=s2[s2.length()-1]-'A'+1;
        if(b==6){
            b--;
        }
        if(d==6){
            d--;
        }
        if((b<=3&&d<=3)||(b>=4&&d>=4)){
            cout << "1";
            if(abs(b-d)==1){
                cout << "1";
            }else{
                cout << "0";
            }
        }else{
            cout << "00";
        }
    }else{
        cout << "000";
    }
    return 0;
}
