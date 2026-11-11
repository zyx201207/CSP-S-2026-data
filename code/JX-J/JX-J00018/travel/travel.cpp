#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int x1=(c1[0]-'0')*10+(c1[1]-'0');
    int x2=(s1[0]-'0')*10+(s1[1]-'0');
    int x3=(c2[0]-'0')*10+(c2[1]-'0');
    int x4=(s2[0]-'0')*10+(s2[1]-'0');
    char y1=s1[2];
    char y2=s2[2];
    if(x1==x3){
        cout<<1;
        if(x2==x4){
            cout<<1;
            if((y1>='D' && y1<='E' && y2>='D' && y2<='E') || (y1>='A' && y1<='C' && y2>='A' && y2<='C')){
                cout<<1;
                if(abs(int(y1-y2))==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
