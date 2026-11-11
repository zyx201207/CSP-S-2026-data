#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
///////////// I want to AC.
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        int x1=stoi(s1);
        int x2=stoi(s2);
        if(x1==x2){
            char c1=s1[2];
            char c2=s2[2];
            if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C')){
                if(abs(int(c1-c2))==1){
                    cout<<"1111\n";
                }else{
                    cout<<"1110\n";
                }
            }else{
                cout<<"1100\n";
            }
        }else{
            cout<<"1000\n";
        }
    }else{
        cout<<"0000\n";
    }
    return 0;
}
