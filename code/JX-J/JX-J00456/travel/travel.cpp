#include<bits/stdc++.h>
using namespace std;
string s3="ABC",s4="DF";
int main(){
    int c1,c2;
    string s1,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    for(int i=0;i<3;i++)
        cin>>s1[i];
    cin>>c2;
    for(int i=0;i<3;i++)
        cin>>s2[i];
    if(c1==c2) {
        cout<<1;
        if(s1[1]==s2[1]){
            cout<<1;
        }

    }
    else cout<<0<<0<<0<<0;
    for(int i=0;i<3;i++){
        if(s1[2]==s3[i]and s2[2]==s3[i+1] or s2[2]==s3[i-1]) {
            cout<<1<<1;
            break;
        }
    }
    for(int i=0;i<1;i++){
        if(s1[2]==s4[i] and s2[2]==s4[i+1] or s2[2]==s2[i-1]) {
            cout<<1<<1;
            break;
        }
        else{
            cout<<0<<0;
            break;
        }
    }
    return 0;
}
