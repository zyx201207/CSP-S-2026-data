#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    int a,b;
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]-'0';
    a*=10;
    a+=s1[1]-'0';
    b=s2[0]-'0';
    b*=10;
    b+=s2[1]-'0';
    if(c1==c2){
        if(a==b){
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    if(s1[2]=='A'&&s2[2]=='B'){
                        cout<<"1111";
                    }
                    else if(s1[2]=='B'){
                        if(s2[2]=='A'||s2[2]=='C'){
                            cout<<"1111";
                        }
                    }
                    else if(s1[2]=='C'&&s2[2]=='B'){
                        cout<<"1111";
                    }
                    else{
                        cout<<"1110";
                    }
                }
            }
            else if(s2[2]=='D'||s2[2]=='F'){
                cout<<"1111";
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
