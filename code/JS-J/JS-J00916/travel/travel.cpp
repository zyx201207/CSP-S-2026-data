#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int c1 = (a[0]-'0')*10+(a[1]-'0');
    int c2 = (c[0]-'0')*10+(c[1]-'0');
    if(c1==c2){
        cout<<"1";
        int s1 = (b[0]-'0')*10+(b[1]-'0');
        int s2 = (d[0]-'0')*10+(d[1]-'0');
        if(s1==s2){
            cout<<"1";
            int z1 = b[2]-'A';
            int z2 = d[2]-'A';
            if(z1+z2==8||z1+z2<=2||(z1+z2==3&&(z1!=0&&z2!=0))){
                cout<<"1";
                if((z1+1==z2&&(b[2]!='C'))||(z1-1==z2&&(b[2]!='D'))||(z1==5&&z2==3)||(z1==3&&z2==5)){
                    cout<<"1";
                }
                else cout<<"0";
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
