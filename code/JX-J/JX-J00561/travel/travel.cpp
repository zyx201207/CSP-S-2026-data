#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int h1,h2;
    h1=(s1[0]-'0')*10+s1[1]-'0';
    h2=(s2[0]-'0')*10+s2[1]-'0';
    char m1,m2;
    m1=s1[2];
    m2=s2[2];
    //cout<<h1<<" "<<h2;
    if(c1==c2){
        if(h1==h2){
            if(('A'<=m1 and m1<='C' and 'A'<=m2 and m2<='C') or ('D'<=m1 and m1<='F' and 'D'<=m2 and m2<='F')){
                //cout<<1110;
                if('A'<=m1 and m1<='C' and 'A'<=m2 and m2<='C'){
                    if(abs(m1-m2)==1){
                        cout<<"1111";
                    }
                    else{
                        cout<<"1110";
                    }
                }
                else{
                    cout<<"1111";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
