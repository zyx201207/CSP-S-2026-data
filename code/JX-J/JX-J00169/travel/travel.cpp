#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool a(char n,char m){
    if(n=='A' || n=='B' || n=='C'){
        if(m=='A' || m=='B' || m=='C'){
            return 1;
        }else return 0;
    }
    else{
        if(m=='E' || m=='F'){
            cout<<1;
        }else cout<<0;
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<1;

        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;

            if( a(s1[2],s2[2])==1 ){
                cout<<1;

                if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1){
                    cout<<1;
                }else cout<<"00";

            }else cout<<"00";

        }else cout<<"000";

    }else cout<<"0000";

    cout<<"\n";
    return 0;
}
