#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c1,c2;
string s1,s2;
int get1(string s){
    return (s[0]-'0')*10+s[1]-'0';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        cout<<1;
        if (get1(s1)==get1(s2)){
            cout<<1;
            int r1=s1[2]-'A',r2=s2[2]-'A';
            if ((r1<3&&r2<3)||(r1>=3&&r2>=3)){
                cout<<1;
                if (abs(r1-r2)==1||(r1==3&&r2==5)||(r1==5&&r2==3))
                    cout<<1;
                else
                    cout<<"0";
            }else
                cout<<"00";
        }else
            cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
