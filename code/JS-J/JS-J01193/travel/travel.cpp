#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int x1=s1[2]-65,x2=s2[2]-65;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[1]!=s2[1]||s1[0]!=s2[0]){
        cout<<1000;
        return 0;
    }
    if(x1>=3&&x2>=3){
        cout<<1111;
        return 0;
    }
    if(x1<3&&x2<3){
        if((x1-x2)%2==1||(x1-x2)%2==-1){
            cout<<1111;
            return 0;
        }
        else{
            cout<<1110;
            return 0;
        }
    }
    cout<<1100;
    return 0;
}
