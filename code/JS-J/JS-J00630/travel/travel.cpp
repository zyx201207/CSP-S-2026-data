#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);//read,write
    //don`t forget!!!!
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<s1<<c2<<s2<<endl;
    char a=s1[2],b=s2[2];
    //cout<<a<<" "<<b<<endl;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(((a=='A'||a=='B'|a=='C')&&
            (b=='A'||b=='B'|b=='C'))||
            ((a=='D'||a=='F')&&(b=='D'||b=='F'))
            ){
                cout<<1;
                if((a=='A'&&b=='B')||(a=='B'&&b=='A')||
                (a=='C'&&b=='B')||(a=='B'&&b=='C')||
                (a=='D'&&b=='F')||(a=='F'&&b=='D'))
                cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}