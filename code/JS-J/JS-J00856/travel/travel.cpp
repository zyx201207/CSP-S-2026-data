#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        int z1=(s1[0]-'0')*10+s1[1]-'0',z2=(s2[0]-'0')*10+s2[1]-'0';
        if(z1==z2){
            cout<<"1";
            int n1=s1[2],n2=s2[2];
            if(n1<='C'&&n2<='C'||n1>='D'&&n2>='D'){
                cout<<"1";
                if(abs(n1-n2)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}