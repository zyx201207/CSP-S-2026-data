#include<iostream>
#include<cstdio>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool test1,test2 = 0;
    if(s2[2] == 'D'||s2[2] == 'F'){
        test2 = 1;//
    }
    if(c1 == c2){
        cout<<"1";//
        if(s1[0] == s2[0]&&s1[1] == s2[1]){
            cout<<"1";//
            if(s1[2] == 'D'||s1[2] == 'F'){
                test1 = 1;//
                if(s2[2] == 'D'||s2[2] == 'F'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }else{
                if(s1[2] == 'A' and s2[2] =='C'){
                    cout<<"10";
                }else if(s1[2] == 'C' and s2[2] =='A'){
                    cout<<"10";
                }else if(test1 == 1||test2 == 1){
                    cout<<"00";
                }else{
                    cout<<"11";
                }
            }

        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
