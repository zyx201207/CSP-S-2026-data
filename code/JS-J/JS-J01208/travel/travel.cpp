#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //g++ a.cpp -o a -o2 -std=c++14 
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
                cout<<1111;

            }
            else if(s2[2]=='D'||s2[2]=='F'||s4[2]=='D'||s4[2]=='F'){
                cout<<1100;
            }
            else if(abs(s2[2]-s4[2])==1)cout<<1111;
            else cout<<1110;
        }
        else cout<<1000;

    }
    else{
        cout<<0000;
    }
    return 0;
}