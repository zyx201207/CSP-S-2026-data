#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>c1>>s1>>c2>>s2;
    int a,b,x,y;
    a=(c1[0]-'0')*10+c1[1]-'0';
    b=(c2[0]-'0')*10+c2[1]-'0';
    x=(s1[0]-'0')*10+s1[1]-'0';
    y=(s2[0]-'0')*10+s2[1]-'0';
    char n,m;
    n=s1[2],m=s2[2];
    if(a==b){
        cout<<1;
        if(x==y){
            cout<<1;
            if((n=='A'&&(m=='B'||m=='C'))||(n=='B'&&(m=='A'||m=='C'))||(n=='C'&&(m=='B'||m=='A'))||
               (n=='D'&&(m=='F'))||(n=='F'&&(m=='D'))){
                cout<<1;
                if((n=='A'&&m=='B')||(n=='B'&&(m=='A'||m=='C'))||(n=='C'&&m=='B')||(n=='D'&&m=='F')||(n=='F'&&m=='D'))
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
